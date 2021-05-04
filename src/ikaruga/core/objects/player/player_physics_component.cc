//
// Created by rishi on 16-04-2021.
//

#include <game_engine/collision/circle_collider.h>
#include <game_engine/collision/box_collider.h>
#include "ikaruga/core/objects/player/player_physics_component.h"

namespace ikaruga::objects::player {
void PlayerPhysicsComponent::Update() {
  PhysicsComponent::Update();
  velocity_ = glm::vec2(0, 0);
}

void PlayerPhysicsComponent::receive(int message) {
  switch (message) {
    case 1:
      velocity_.y = -speed_;
      break;
    case 2:
      velocity_.x = -speed_;
      break;
    case 3:
      velocity_.y = speed_;
      break;
    case 4:
      velocity_.x = speed_;
      break;
  }
}

PlayerPhysicsComponent::PlayerPhysicsComponent(const glm::vec2 &position,
                                               const glm::vec2 &velocity)
    : PhysicsComponent(position, velocity) {
  collider_mesh_.AddCollider(new game_engine::CircleCollider(
      position_ + glm::vec2(38, 24), 8.0));
  collider_mesh_.AddCollider(new game_engine::CircleCollider(
      position_ + glm::vec2(28, 35), 7.0));
  collider_mesh_.AddCollider(new game_engine::CircleCollider(
      position_ + glm::vec2(48, 35), 7.0));
  collider_mesh_.AddCollider(new game_engine::BoxCollider(
      position_ + glm::vec2(9, 15), 7.0, 20.0));
  collider_mesh_.AddCollider(new game_engine::BoxCollider(
      position_ + glm::vec2(60, 15), 7.0, 20.0));
}
}