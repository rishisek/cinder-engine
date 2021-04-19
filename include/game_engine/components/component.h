//
// Created by rishi on 17-04-2021.
//
#pragma once

namespace game_engine {
class Component {
 public:
  virtual ~Component() = 0;
  // TODO: messaging without magic numbers
  virtual void receive(int message) = 0;
 protected:
  Component() = default;
};
}