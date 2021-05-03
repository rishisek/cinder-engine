//
// Created by rishi on 22-04-2021.
//
#include <ikaruga/core/objects/enemy/enemy_physics_component.h>
#include <game_engine/collision/circle_collider.h>
#include <game_engine/collision/box_collider.h>

namespace ikaruga::objects::enemy {
void EnemyPhysicsComponent::Update() {
  velocity_ = movement_strategy_->GetNextVelocity(velocity_);
  PhysicsComponent::Update();
}

void EnemyPhysicsComponent::receive(int message) {}

EnemyPhysicsComponent::EnemyPhysicsComponent(const glm::vec2 &position,
                                             const glm::vec2 &velocity,
                                             game_engine::ColliderMesh &&collider_mesh,
                                             movement::MovementStrategy *movement_strategy)
    : PhysicsComponent(position, velocity, std::move(collider_mesh)),
      movement_strategy_(movement_strategy) {
  collider_mesh_.AddCollider(new game_engine::CircleCollider(
      position_ + glm::vec2(28, 35), 7.0));
  collider_mesh_.AddCollider(new game_engine::CircleCollider(
      position_ + glm::vec2(48, 35), 7.0));
  collider_mesh_.AddCollider(new game_engine::BoxCollider(
      position_ + glm::vec2(7, 15), 10.0, 30.0));
  collider_mesh_.AddCollider(new game_engine::BoxCollider(
      position_ + glm::vec2(58, 15), 10.0, 30.0));
  collider_mesh_.AddCollider(new game_engine::BoxCollider(
      position_ + glm::vec2(15, 7), 42.0, 20.0));
}

}