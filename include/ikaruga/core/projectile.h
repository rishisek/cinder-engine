//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/game_object.h>
#include "projectile_type.h"

namespace ikaruga {
class Projectile : game_engine::GameObject {
 public:
 private:
  ProjectileType type_;
};
}