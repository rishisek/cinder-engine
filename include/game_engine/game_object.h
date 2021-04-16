//
// Created by rishi on 16-04-2021.
//

#pragma once

#include <glm/vec2.hpp>

namespace game_engine {
class PhysicsComponent;
class InputComponent;

class GameObject {
 public:

  GameObject(PhysicsComponent *physics_component);
  virtual void Update(); 
  
  PhysicsComponent *GetPhysicsComponent() const;
 protected:
  PhysicsComponent* physics_component_;
};
}