//
// Created by rishi on 23-04-2021.
//

#include "ikaruga/game/game_instance.h"
#include <game_engine/collision/circle_collider.h>
#include <ikaruga/core/objects/player/player_physics_component.h>
#include <ikaruga/core/objects/player/player_input_component.h>
#include <ikaruga/core/objects/enemy/movement/sine_line_movement_physics_component.h>
#include "cinder/gl/gl.h"

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
  for (const ikaruga::objects::projectile::Projectile
        *projectile: world_.GetProjectiles()) {
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
  std::vector<projectile::ProjectileType> player_projectile_types{
      projectile::ProjectileType(5, ci::Color(0, 1, 0), 50),
      projectile::ProjectileType(5, ci::Color(1, 0, 0), 25)
  };
  enemy::EnemyType
      enemy_type(10,
                 enemy::movement::kSineLine,
                 player_projectile_types,
                 ci::Color(0.5, 0.5, 0));
  game_engine::PhysicsComponent *physics_component =
      new enemy::movement::SineLineMovementPhysicsComponent(glm::vec2(300, 100),
                                                            glm::vec2(1, 0));
  physics_component->AddCollider(new game_engine::CircleCollider(glm::vec2(300,
                                                                           100),
                                                                 30));
  world_.AddEnemy(std::make_unique<enemy::Enemy>(physics_component,
                                                 enemy_type));
}

double GameInstance::GetWidth() const {
  return width_;
}

}
