//
// Created by rishi on 16-04-2021.
//

#pragma once

#include <glm/vec2.hpp>

namespace game_engine {
class PhysicsComponent;

class GameObject {
 public:
  GameObject(PhysicsComponent *physics_component);
  virtual ~GameObject() = 0;

  virtual void Update(game_engine::GameObject &world);

  PhysicsComponent *GetPhysicsComponent() const;
 protected:
  PhysicsComponent *physics_component_;
};
}