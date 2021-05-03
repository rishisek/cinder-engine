//
// Created by rishi on 01-05-2021.
//
#pragma once
#include <game_engine/components/graphics_component.h>

namespace ikaruga::objects::player {
class PlayerGraphicsComponent : public game_engine::GraphicsComponent {
 public:
  PlayerGraphicsComponent(const glm::vec2 &position);
  void Render() const override;
  void receive(int message) override;
};
}