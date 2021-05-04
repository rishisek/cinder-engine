//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/world/world.h>
#include <ikaruga/core/objects/player/player.h>
#include <ikaruga/core/objects/enemy/enemy_type.h>
#include <game_engine/components/physics_component.h>
#include <cinder/gl/gl.h>

namespace ikaruga::world {
using objects::projectile::Projectile;
using ikaruga::objects::enemy::Enemy;

const std::vector<std::unique_ptr<Projectile>> &World::GetPlayerProjectiles() const {
  return player_projectiles_;
}

void World::UpdateProjectiles() {
  for (std::unique_ptr<Projectile> &projectile: player_projectiles_) {
    projectile->Update(*this);
  }
  for (std::unique_ptr<Projectile> &projectile: enemy_projectiles_) {
    projectile->Update(*this);
  }
}

void World::UpdateEnemies() {
  for (std::unique_ptr<Enemy> &enemy: enemies_) {
    enemy->Update(*this);
  }
}

void World::Update() {
  UpdateProjectiles();
  UpdateEnemies();
  ResolveProjectileEnemyCollisions();
}

void World::AddPlayerProjectile(std::unique_ptr<Projectile> &&projectile) {
  player_projectiles_.push_back(std::move(projectile));
}

void World::AddPlayerProjectile(Projectile *const projectile) {
  // Move ownership to a new std::unique_ptr that can be added to world.
  std::unique_ptr<Projectile> ptr;
  ptr.reset(projectile);
  // std::move required for R-value form of argument. 
  AddPlayerProjectile(std::move(ptr));
}

void World::AddEnemyProjectile(std::unique_ptr<Projectile> &&projectile) {
  enemy_projectiles_.push_back(std::move(projectile));
}

void World::AddEnemyProjectile(Projectile *const projectile) {
  // Move ownership to a new std::unique_ptr that can be added to world.
  std::unique_ptr<Projectile> ptr;
  ptr.reset(projectile);
  // std::move required for R-value form of argument. 
  AddEnemyProjectile(std::move(ptr));
}

void World::AddEnemy(std::unique_ptr<Enemy> &&enemy) {
  enemies_.push_back(std::move(enemy));
}

World::World() {}

World::~World() {}

const std::vector<std::unique_ptr<Enemy>> &World::GetEnemies() const {
  return enemies_;
}

void World::ResolveProjectileEnemyCollisions() {
  for (auto itr = player_projectiles_.begin(); itr != player_projectiles_.end();
       ++itr) {
    auto iterator = std::remove_if(enemies_.begin(),
                                   enemies_.end(),
                                   [&](std::unique_ptr<Enemy> &obj) {
                                     if (obj->Collides((*itr).get())) {
                                       player_ref_->IncrementScore(obj->GetType()->GetKillScore());
                                       return true;
                                     }
                                     return false;
                                   });
    if (iterator != enemies_.end()) {
      enemies_.erase(iterator, enemies_.end());
      itr = player_projectiles_.erase(itr);
      if (itr == player_projectiles_.end()) {
        break;
      }
    }
  }
}

void World::Setup(ikaruga::objects::player::Player *player) {
  player_ref_ = player;
}

objects::player::Player *World::GetPlayerRef() const {
  return player_ref_;
}

void World::Draw() {
  for (const std::unique_ptr<ikaruga::objects::projectile::Projectile>
        &projectile: player_projectiles_) {
    ci::gl::color(projectile->GetType().GetColor());
    ci::gl::drawSolidCircle(projectile->GetPhysicsComponent()->GetPosition(),
                            projectile->GetType().GetRadius());
  }
  for (const std::unique_ptr<ikaruga::objects::projectile::Projectile>
        &projectile: enemy_projectiles_) {
    ci::gl::color(projectile->GetType().GetColor());
    ci::gl::drawSolidCircle(projectile->GetPhysicsComponent()->GetPosition(),
                            projectile->GetType().GetRadius());
  }
  for (std::unique_ptr<Enemy> const &enemy: enemies_) {
    enemy->GetGraphicsComponent()->Draw();
    enemy->GetPhysicsComponent()->GetColliderMesh().Draw();
  }
}
}