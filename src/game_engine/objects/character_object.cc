//
// Created by rishi on 16-04-2021.
//

#include "game_engine/objects/character_object.h"

namespace game_engine {

CharacterObject::CharacterObject(PhysicsComponent *physics_component,
                                 int max_health)
    : GameObject(physics_component),
      max_health_(max_health),
      health_(max_health) {}

CharacterObject::~CharacterObject() {
}

void CharacterObject::Serialize(nlohmann::json &json) const {
//  GameObject::Serialize(json);
  json["max_health"] = max_health_;
  json["health"] = health_;
}

void CharacterObject::Deserialize(const nlohmann::json &json) {
//  GameObject::Deserialize(json);
  max_health_ = json["max_health"];
  health_ = json["health"];
}

int CharacterObject::GetMaxHealth() const {
  return max_health_;
}

int CharacterObject::GetHealth() const {
  return health_;
}

void to_json(nlohmann::json &json, const CharacterObject &character_object) {
  character_object.Serialize(json);
}

void from_json(const nlohmann::json &json, CharacterObject &character_object) {
  character_object.Deserialize(json);
}
}