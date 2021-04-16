//
// Created by rishi on 16-04-2021.
//

#include "game_engine/game_object.h"
#include "game_engine/physics_component.h"

namespace game_engine {
GameObject::GameObject(PhysicsComponent *physics_component)
    : physics_component_(physics_component) {}

PhysicsComponent *GameObject::GetPhysicsComponent() const {
  return physics_component_;
}

void GameObject::Update(game_engine::GameObject &world) {
  physics_component_->Update();
}
}