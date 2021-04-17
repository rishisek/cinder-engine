//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "game_object.h"

namespace game_engine {
template<typename T>
class ControllableObject : public T {
 public:
  ControllableObject(game_engine::PhysicsComponent *physics_component,
                     game_engine::InputComponent *input_component)
      : input_component_(input_component), T(physics_component) {}

  InputComponent *GetInputComponent() const;
 protected:
  InputComponent *input_component_;
};

template<typename T>
InputComponent *ControllableObject<T>::GetInputComponent() const {
  return input_component_;
}
}