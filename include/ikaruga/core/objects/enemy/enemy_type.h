//
// Created by rishi on 16-04-2021.
//
#pragma once

namespace ikaruga::objects::enemy {
class EnemyType {
 public:
  float GetMaxHealth() const;
 private:
  float max_health_;
};
}