//
// Created by rishi on 19-04-2021.
//
#pragma once

namespace game_engine {
// Base class for game worlds to allow component interaction
class GameWorld {
 public:
  virtual ~GameWorld() = 0;
  virtual void Update() = 0;
  virtual void Draw() = 0;
};
}