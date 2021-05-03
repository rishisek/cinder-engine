//
// Created by rishi on 22-04-2021.
//
#pragma once

#include <game_engine/components/physics_component.h>

namespace ikaruga::objects::enemy::movement {
class SineLoopMovementPhysicsComponent : public game_engine::PhysicsComponent {
 public:
  SineLoopMovementPhysicsComponent(const glm::vec2 &position,
                                   const glm::vec2 &velocity,
                                   game_engine::ColliderMesh &&collider_mesh);
  SineLoopMovementPhysicsComponent(const glm::vec2 &position = glm::vec2(),
                                   const glm::vec2 &velocity = glm::vec2());
  void Update() override;
  void receive(int message) override;
 protected:
  float current_sine_y_degree_ = 90.0f;
  float current_sine_x_degree_ = 90.0f;
  float current_line_point_ = 0.0f;
  void UpdateVelocity();
};
}