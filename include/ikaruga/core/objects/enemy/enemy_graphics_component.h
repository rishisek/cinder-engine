//
// Created by rishi on 01-05-2021.
//
#pragma once
#include <game_engine/components/graphics_component.h>
#include <cinder/Color.h>

namespace ikaruga::objects::enemy {
class EnemyGraphicsComponent : public game_engine::GraphicsComponent {
 public:
  EnemyGraphicsComponent(const glm::vec2 &position,
                         const ci::ColorT<float> &enemy_color);
  void Render() const override;
  void receive(int message) override;
 private:
  ci::ColorT<float> color_;
};
}