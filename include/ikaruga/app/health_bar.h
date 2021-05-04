//
// Created by rishi on 04-05-2021.
//

#pragma once
#include <glm/vec2.hpp>

namespace ikaruga::app {
class HealthBar {
 public:
  static void Draw(int max_health, int health);
 private:
  static void DrawHealthBlock(glm::vec2 position);
  static void DrawDamageBlock(glm::vec2 position);
};
}