//
// Created by rishi on 16-04-2021.
//

#include <game_engine/game_world.h>
#include "game_engine/objects/game_object.h"
#include "game_engine/components/physics_component.h"

namespace game_engine {
GameObject::GameObject(PhysicsComponent *physics_component)
    : physics_component_(physics_component) {}

PhysicsComponent *GameObject::GetPhysicsComponent() const {
  return physics_component_;
}

void GameObject::Update(game_engine::GameWorld &game_world) {
  physics_component_->Update();
}

GameObject::~GameObject() {
  delete physics_component_;
}

bool GameObject::Collides(GameObject *const other) const {
  return physics_component_->Collides(other->physics_component_);
}

void to_json(nlohmann::json &json, const GameObject &game_object) {
  game_object.Serialize(json);
}

void from_json(const nlohmann::json &json, GameObject &game_object) {
  game_object.Deserialize(json);
}
}