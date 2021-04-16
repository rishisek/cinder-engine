//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/physics_component.h>

namespace ikaruga {
class PlayerPhysicsComponent : public game_engine::PhysicsComponent {
 public:
  void Update() override;
};
}
