//
// Created by rishi on 19-04-2021.
//
#pragma once

namespace game_engine {
class GameWorld {
 public:
  virtual ~GameWorld() = 0;
  virtual void Update() = 0;
};
}