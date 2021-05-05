//
// Created by rishi on 23-04-2021.
//

#include <ikaruga/game/game_instance.h>
#include <ikaruga/core/objects/player/player_physics_component.h>
#include <ikaruga/core/objects/player/player_input_component.h>
#include <ikaruga/core/objects/enemy/enemy_factory.h>
#include <ikaruga/core/objects/enemy/enemy_type.h>
#include <ikaruga/core/objects/projectile/projectile_factory.h>
#include <cinder/gl/gl.h>
#include <cinder/app/AppBase.h>

namespace ikaruga::game {
using namespace ikaruga::objects;

GameInstance::GameInstance() : world_() {}

void GameInstance::Setup() {
  SetupPlayer();
  SetupEnemies();
}

void GameInstance::Draw() {
  player_->GetGraphicsComponent()->Draw();
//  player_->GetPhysicsComponent()->GetColliderMesh().Draw();
  world_.Draw();
}

void GameInstance::Update() {
  player_->Update(world_);
  world_.Update();
  if (player_->GetHealth() == 0) {
    player_loss_ = true;
    ended_ = true;
  }
  if (world_.GetEnemies().size() == 0) {
    player_win_ = true;
    ended_ = true;
  }
}

GameInstance::~GameInstance() {
  delete player_;
}

void GameInstance::SetupPlayer() {
  std::vector<projectile::ProjectileType *> player_projectile_types{
      new projectile::ProjectileType("type1", 5, ci::Color(0, 1, 0), 50, 4),
      new projectile::ProjectileType("type2", 5, ci::Color(1, 0, 0), 25, 5)
  };
  player_ = new player::Player(
      new player::PlayerPhysicsComponent(glm::vec2(300, 450), glm::vec2(0, 0)),
      new player::PlayerInputComponent(),
      new player::PlayerGraphicsComponent(glm::vec2(300, 450)),
      player_projectile_types,
      0);
  world_.Setup(player_);
}

void GameInstance::SetupEnemies() {
  std::ifstream ifstream(ci::app::loadAsset("enemy.json")->getFilePath());
  nlohmann::json json;
  ifstream >> json;
  for (const nlohmann::json &projectile_type_json: json["projectile_types"]) {
    projectile::ProjectileFactory::AddProjectileType(new projectile::ProjectileType(
        projectile_type_json));
  }
  for (const nlohmann::json &enemy_type_json: json["enemy_types"]) {
    enemy::EnemyFactory::AddEnemyType(new enemy::EnemyType(enemy_type_json));
  }
  for (const nlohmann::json &enemy_json: json["enemies"]) {
    world_.AddEnemy(std::make_unique<enemy::Enemy>(enemy_json));
  }
}

double GameInstance::GetWidth() const {
  return width_;
}

double GameInstance::GetHeight() const {
  return height_;
}

player::Player *GameInstance::GetPlayer() const {
  return player_;
}

bool GameInstance::IsPlayerLoss() const {
  return player_loss_;
}

bool GameInstance::IsPlayerWin() const {
  return player_win_;
}

bool GameInstance::IsEnded() const {
  return ended_;
}

}
