//
// Created by rishi on 04-05-2021.
//

#include <ikaruga/app/health_bar.h>
#include <cinder/gl/gl.h>

namespace ikaruga::app {
void HealthBar::Draw(int max_health, int health) {
  for (int i = max_health; i >= max_health - health; i--) {
    DrawHealthBlock(glm::vec2(0, i * 10));
  }
  for (int i = max_health - health; i >= 0; i--) {
    DrawDamageBlock(glm::vec2(0, i * 10));
  }
}

void HealthBar::DrawDamageBlock(glm::vec2 position) {
  ci::gl::color(1, 0, 0);
  ci::gl::drawSolidRect(ci::Rectf(position, position + glm::vec2(10, 10)));
}

void HealthBar::DrawHealthBlock(glm::vec2 position) {
  ci::gl::color(0, 0, 1);
  ci::gl::drawSolidRect(ci::Rectf(position, position + glm::vec2(10, 10)));
}
}