//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/game_object.h>
#include "projectile_type.h"

namespace ikaruga {
class Projectile : public game_engine::GameObject {
 public:
  Projectile(ProjectileType type,
             glm::vec2 position,
             glm::vec2 velocity);
  
  void Update() override;

  const ProjectileType &GetType() const;
 private:
  ProjectileType type_;
};
}