//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/objects/game_object.h>
#include <game_engine/game_world.h>
#include "projectile_type.h"

namespace ikaruga::objects::projectile {
class Projectile : public game_engine::GameObject {
 public:
  Projectile(ProjectileType type,
             game_engine::PhysicsComponent *physics_component);

  void Update(game_engine::GameWorld &world) override;

  const ProjectileType &GetType() const;
 private:
  ProjectileType type_;
};
}