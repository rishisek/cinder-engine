//
// Created by rishi on 22-04-2021.
//
#include <ikaruga/core/objects/enemy/movement/sine_line_movement_physics_component.h>
#include <ikaruga/core/objects/enemy/movement/movement_utils.h>

namespace ikaruga::objects::enemy::movement {
void SineLineMovementPhysicsComponent::Update() {
  UpdateVelocity();
  PhysicsComponent::Update();
}

void SineLineMovementPhysicsComponent::receive(int message) {

}

SineLineMovementPhysicsComponent::SineLineMovementPhysicsComponent(const glm::vec2 &position,
                                                                   const glm::vec2 &velocity)
    : PhysicsComponent(position, velocity) {}

void SineLineMovementPhysicsComponent::UpdateVelocity() {
  velocity_.x =
      MovementUtils::ComputeNextLinearVelocity(velocity_.x,
                                               current_line_point_,
                                               period_ * period_count_);
  current_line_point_ += velocity_.x;
  velocity_.y =
      MovementUtils::ComputeNextSineVelocity(current_sine_y_degree_,
                                             amplitude_,
                                             period_);
}
}