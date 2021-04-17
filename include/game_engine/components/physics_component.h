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
  bool Collides(GameObject const &other);
  virtual void Update() = 0;

  const glm::vec2 &GetPosition() const;
  void SetPosition(const glm::vec2 &position);
  const glm::vec2 &GetVelocity() const;
  void SetVelocity(const glm::vec2 &velocity);
 protected:
  ColliderMesh collider_;
  glm::vec2 position_;
  glm::vec2 velocity_;

  void UpdatePosition();
};
}