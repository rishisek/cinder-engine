//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/player/player_physics_component.h"

namespace ikaruga{
void PlayerPhysicsComponent::Update() {
  UpdatePosition();
}

void PlayerPhysicsComponent::receive(int message) {

}
}