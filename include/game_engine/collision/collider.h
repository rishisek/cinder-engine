//
// Created by rishi on 17-04-2021.
//
#pragma once

namespace game_engine {
class Collider {
 public:
  virtual ~Collider();

  virtual bool IsCollision(Collider const &other) = 0;
 private:
};
}