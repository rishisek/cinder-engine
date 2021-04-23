//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "game_engine/objects/game_object.h"
#include "game_engine/collision/collider_mesh.h"
#include "component.h"

namespace game_engine {
class PhysicsComponent : public Component {
 public:
  virtual ~PhysicsComponent() = 0;

  virtual void Update();

  bool Collides(GameObject *const other);
  void AddCollider(Collider *collider);

  const glm::vec2 &GetPosition() const;
  void SetPosition(const glm::vec2 &position);
  const glm::vec2 &GetVelocity() const;
  void SetVelocity(const glm::vec2 &velocity);
 protected:
  PhysicsComponent(const glm::vec2 &position = glm::vec2(),
                   const glm::vec2 &velocity = glm::vec2());

  ColliderMesh collider_mesh_;
  glm::vec2 position_;
  glm::vec2 velocity_;

  void UpdatePosition();
  virtual void UpdateColliderMesh();
};
}