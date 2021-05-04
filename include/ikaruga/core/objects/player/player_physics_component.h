//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/components/physics_component.h>

namespace ikaruga::objects::player {
class PlayerPhysicsComponent : public game_engine::PhysicsComponent {
 public:
  PlayerPhysicsComponent(const glm::vec2 &position,
                         const glm::vec2 &velocity);
  void Update() override;
  void receive(int message) override;
 private:
  float speed_ = 2.0f;
};
}
