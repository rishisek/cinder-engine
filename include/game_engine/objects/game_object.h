//
// Created by rishi on 16-04-2021.
//

#pragma once
#include <game_engine/json_serializable.h>
#include <game_engine/game_world.h>
#include <glm/vec2.hpp>

namespace game_engine {
class PhysicsComponent;

class GameObject : public JsonSerializable {
 public:
  virtual ~GameObject() = 0;

  virtual void Update(game_engine::GameWorld &world);
  bool Collides(GameObject *const other) const;

  void Serialize(nlohmann::json &json) const override = 0;
  void Deserialize(const nlohmann::json &json) override = 0;

  PhysicsComponent *GetPhysicsComponent() const;
 protected:
  GameObject(PhysicsComponent *physics_component);
  PhysicsComponent *physics_component_;
};

void to_json(nlohmann::json &json, const GameObject &game_object);

void from_json(const nlohmann::json &json, GameObject &game_object);
}