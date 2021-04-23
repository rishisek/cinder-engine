//
// Created by rishi on 22-04-2021.
//
#include <ikaruga/core/objects/enemy/movement/sine_loop_movement_physics_component.h>
#include <ikaruga/core/objects/enemy/movement/movement_utils.h>

namespace ikaruga::objects::enemy::movement {
void SineLoopMovementPhysicsComponent::Update() {
  UpdateVelocity();
  PhysicsComponent::Update();
}

void SineLoopMovementPhysicsComponent::receive(int message) {

}

SineLoopMovementPhysicsComponent::SineLoopMovementPhysicsComponent(const glm::vec2 &position,
                                                                   const glm::vec2 &velocity)
    : PhysicsComponent(position, velocity) {}

void SineLoopMovementPhysicsComponent::UpdateVelocity() {
  velocity_.x =
      MovementUtils::ComputeNextSineVelocity(current_sine_x_degree_,
                                             4.5f,
                                             400.0f);
  velocity_.y =
      MovementUtils::ComputeNextSineVelocity(current_sine_y_degree_,
                                             10.0f,
                                             50.0f);
}
}