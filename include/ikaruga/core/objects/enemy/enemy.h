//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/flyer_character.h>
#include "enemy_type.h"

namespace ikaruga {
class Enemy : public FlyerCharacter {
 public:
  Enemy(EnemyType const& enemy_type);
  void Update() override;
 private:
};
}