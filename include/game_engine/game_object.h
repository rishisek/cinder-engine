//
// Created by rishi on 16-04-2021.
//

#pragma once

#include <glm/vec2.hpp>
#include "collider.h"

namespace game_engine {
class GameObject {
 public:
  bool Collides(GameObject const &other);
  virtual void Update() = 0;

  const glm::vec2 &GetPosition() const;
  void SetPosition(const glm::vec2 &position);
  const glm::vec2 &GetVelocity() const;
  void SetVelocity(const glm::vec2 &velocity);
 protected:
  Collider collider_;
  glm::vec2 position_;
  glm::vec2 velocity_;

  void UpdatePosition();
};
}