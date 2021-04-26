//
// Created by rishi on 16-04-2021.
//
#pragma once
#include <game_engine/objects/game_object.h>

namespace game_engine {
class CharacterObject : public GameObject {
 public:
  virtual ~CharacterObject() = 0;
  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;
 protected:
  CharacterObject(PhysicsComponent *physics_component);
  float max_health_ = 1;
  float health_ = 0;
};

void to_json(nlohmann::json &json, const CharacterObject &character_object);

void from_json(const nlohmann::json &json, CharacterObject &character_object);
}