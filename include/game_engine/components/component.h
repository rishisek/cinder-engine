//
// Created by rishi on 17-04-2021.
//
#pragma once

namespace game_engine {
class Component {
 public:
  virtual ~Component() {}
  virtual void receive(int message) = 0;
};
}