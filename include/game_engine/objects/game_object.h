//
// Created by rishi on 16-04-2021.
//

#pragma once

#include <glm/vec2.hpp>
#include <game_engine/game_world.h>

namespace game_engine {
class PhysicsComponent;

class GameObject {
 public:
  virtual ~GameObject() = 0;

  virtual void Update(game_engine::GameWorld &world);
  bool Collides(GameObject *const other) const;

  PhysicsComponent *GetPhysicsComponent() const;
 protected:
  GameObject(PhysicsComponent *physics_component);
  PhysicsComponent *physics_component_;
};
}