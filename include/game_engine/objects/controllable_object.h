//
// Created by rishi on 16-04-2021.
//
#pragma once
#include <game_engine/components/physics_component.h>
#include <game_engine/components/input_component.h>

namespace game_engine {
template<typename T>
class ControllableObject : public T {
 public:
  virtual ~ControllableObject() = 0;

  InputComponent *GetInputComponent() const;
 protected:
  ControllableObject(game_engine::PhysicsComponent *physics_component,
                     game_engine::InputComponent *input_component)
      : T(physics_component), input_component_(input_component) {}

  InputComponent *input_component_;
};

template<typename T>
InputComponent *ControllableObject<T>::GetInputComponent() const {
  return input_component_;
}

template<typename T>
ControllableObject<T>::~ControllableObject() {
  delete input_component_;
}
}