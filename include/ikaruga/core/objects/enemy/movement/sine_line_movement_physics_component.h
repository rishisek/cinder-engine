//
// Created by rishi on 22-04-2021.
//
#pragma once

#include <game_engine/components/physics_component.h>

namespace ikaruga::objects::enemy::movement {
class SineLineMovementPhysicsComponent : public game_engine::PhysicsComponent {
 public:
  SineLineMovementPhysicsComponent(const glm::vec2 &position,
                                   const glm::vec2 &velocity,
                                   game_engine::ColliderMesh &&collider_mesh);
  SineLineMovementPhysicsComponent(const glm::vec2 &position = glm::vec2(),
                                   const glm::vec2 &velocity = glm::vec2());
  void Update() override;
  void receive(int message) override;
 private:
  int period_count_ = 5;
  float period_ = 75.0f;
  float amplitude_ = 5.0f;
  float current_sine_y_degree_ = 90.0f;
  float current_line_point_ = period_ * period_count_ / 2;
  void UpdateVelocity();
};
}