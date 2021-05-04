//
// Created by rishi on 17-04-2021.
//
#pragma once

namespace game_engine {
// Base component template 
class Component {
 public:
  virtual ~Component() = 0;

  // TODO: messaging without magic numbers
  // Receives a message from Mediator (Mediator pattern)
  virtual void receive(int message) = 0;
 protected:
  Component() = default;
};
}