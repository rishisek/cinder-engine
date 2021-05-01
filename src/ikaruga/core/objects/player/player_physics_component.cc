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
      velocity_.y = -1;
      break;
    case 2:
      velocity_.x = -1;
      break;
    case 3:
      velocity_.y = 1;
      break;
    case 4:
      velocity_.x = 1;
      break;
  }
}

PlayerPhysicsComponent::PlayerPhysicsComponent(const glm::vec2 &position,
                                               const glm::vec2 &velocity)
    : PhysicsComponent(position, velocity) {
  game_engine::Collider
      *circle_collider = new game_engine::CircleCollider(position_, 5.0);
  collider_mesh_.AddCollider(circle_collider);
}
}