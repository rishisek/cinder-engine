//
// Created by rishi on 23-04-2021.
//

#include <ikaruga/game/game_instance.h>
#include <ikaruga/core/objects/player/player_physics_component.h>
#include <ikaruga/core/objects/player/player_input_component.h>
#include <ikaruga/core/objects/enemy/enemy_factory.h>
#include <cinder/gl/gl.h>
#include <cinder/app/AppBase.h>

namespace ikaruga::game {
using namespace ikaruga::objects;

GameInstance::GameInstance() {}

void GameInstance::Setup() {
  SetupPlayer();
  SetupEnemies();
}

void GameInstance::Draw() {
  ci::gl::color(0, 0, 1);
  ci::gl::drawSolidCircle(player_->GetPhysicsComponent()->GetPosition(), 10);
  for (const std::unique_ptr<ikaruga::objects::projectile::Projectile>
        &projectile: world_.GetProjectiles()) {
    ci::gl::color(projectile->GetType().GetColor());
    ci::gl::drawSolidCircle(projectile->GetPhysicsComponent()->GetPosition(),
                            projectile->GetType().GetRadius());
  }
  for (std::unique_ptr<enemy::Enemy> const &enemy: world_.GetEnemies()) {
    ci::gl::color(enemy->GetType().GetColor());
    ci::gl::drawSolidCircle(enemy->GetPhysicsComponent()->GetPosition(),
                            30);
  }
}

void GameInstance::Update() {
  player_->Update(world_);
  world_.Update();
}

GameInstance::~GameInstance() {
  delete player_;

}

void GameInstance::SetupPlayer() {
  std::vector<projectile::ProjectileType> player_projectile_types{
      projectile::ProjectileType(5, ci::Color(0, 1, 0), 50),
      projectile::ProjectileType(5, ci::Color(1, 0, 0), 25)
  };
  player_ = new player::Player(
      new player::PlayerPhysicsComponent(glm::vec2(300, 300), glm::vec2(0, 0)),
      new player::PlayerInputComponent(),
      player_projectile_types);
}

void GameInstance::SetupEnemies() {
  std::ifstream ifstream(ci::app::loadAsset("enemy.json")->getFilePath());
  nlohmann::json json;
  ifstream >> json;
  world_.AddEnemy(std::make_unique<enemy::Enemy>(json));
}

double GameInstance::GetWidth() const {
  return width_;
}

}
