//
// Created by rishi on 17-04-2021.
//
#pragma once

namespace game_engine {
class Component {
 public:

  // TODO: messaging without magic numbers
  virtual void receive(int message) = 0;
};
}