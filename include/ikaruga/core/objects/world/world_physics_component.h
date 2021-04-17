//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/components/physics_component.h>

namespace ikaruga {
class WorldPhysicsComponent : public game_engine::PhysicsComponent {
 public:
  void Update() override;
};
}
