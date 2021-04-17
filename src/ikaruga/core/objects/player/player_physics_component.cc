//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/player/player_physics_component.h"

namespace ikaruga {
void PlayerPhysicsComponent::Update() {
  UpdatePosition();
}

void PlayerPhysicsComponent::receive(int message) {
  switch (message) {
    case 1:
      position_ += glm::vec2(0, -1);
      break;
    case 2:
      position_ += glm::vec2(-1, 0);
      break;
    case 3:
      position_ += glm::vec2(0, 1);
      break;
    case 4:
      position_ += glm::vec2(1, 0);
      break;
  }
}
}