//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/objects/game_object.h>
#include <game_engine/collision/collider_mesh.h>
#include <game_engine/components/component.h>

namespace game_engine {
class PhysicsComponent : public Component, public JsonSerializable {
 public:
  virtual ~PhysicsComponent() = 0;

  virtual void Update();
  bool Collides(PhysicsComponent *const other) const;
  void AddCollider(Collider *collider);

  virtual void Serialize(nlohmann::json &json) const override;
  virtual void Deserialize(const nlohmann::json &json) override;

  const glm::vec2 &GetPosition() const;
  void SetPosition(const glm::vec2 &position);
  const glm::vec2 &GetVelocity() const;
  void SetVelocity(const glm::vec2 &velocity);
  const ColliderMesh &GetColliderMesh() const;
 protected:
  PhysicsComponent(const glm::vec2 &position,
                   const glm::vec2 &velocity,
                   game_engine::ColliderMesh &&collider_mesh);
  PhysicsComponent(const glm::vec2 &position = glm::vec2(),
                   const glm::vec2 &velocity = glm::vec2());

  glm::vec2 position_;
  glm::vec2 velocity_;
  ColliderMesh collider_mesh_;

  void UpdatePosition();
  virtual void UpdateColliderMesh();
};

void to_json(nlohmann::json &json, const PhysicsComponent &component);

void from_json(const nlohmann::json &json, PhysicsComponent &component);

}