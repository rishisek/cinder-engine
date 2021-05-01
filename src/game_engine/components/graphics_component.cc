//
// Created by rishi on 01-05-2021.
//

#include "game_engine/components/graphics_component.h"

namespace game_engine {
GraphicsComponent::~GraphicsComponent() {}

GraphicsComponent::GraphicsComponent(const glm::vec2 &position)
    : position_(position) {}

void GraphicsComponent::Update(const glm::vec2 &position) {
  position_ = position;
}

}
