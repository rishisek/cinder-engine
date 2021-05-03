//
// Created by rishi on 22-04-2021.
//
#include <ikaruga/core/objects/enemy/enemy_physics_component.h>

namespace ikaruga::objects::enemy {
void EnemyPhysicsComponent::Update() {
  velocity_ = movement_strategy_->GetNextVelocity(velocity_);
  PhysicsComponent::Update();
}

void EnemyPhysicsComponent::receive(int message) {

}

EnemyPhysicsComponent::EnemyPhysicsComponent(const glm::vec2 &position,
                                             const glm::vec2 &velocity,
                                             game_engine::ColliderMesh &&collider_mesh,
                                             movement::MovementStrategy *movement_strategy)
    : PhysicsComponent(position, velocity, std::move(collider_mesh)),
      movement_strategy_(movement_strategy) {}

}