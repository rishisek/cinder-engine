//
// Created by rishi on 16-04-2021.
//
#pragma once
#include <game_engine/objects/character_object.h>
#include <ikaruga/core/objects/projectile/projectile_shooter.h>
#include <game_engine/game_world.h>
#include <ikaruga/core/objects/enemy/enemy_type.h>

namespace ikaruga::objects::enemy {
class Enemy
    : public projectile::ProjectileShooter,
      public game_engine::CharacterObject {
 public:
  Enemy(game_engine::PhysicsComponent *physics_component,
        const EnemyType &type);
  void Update(game_engine::GameWorld &world) override;
  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;
  const EnemyType &GetType() const;
 private:
  EnemyType type_;
};

}