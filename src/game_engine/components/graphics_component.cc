//
// Created by rishi on 01-05-2021.
//

#include <game_engine/components/graphics_component.h>
#include <cinder/gl/gl.h>

namespace game_engine {
GraphicsComponent::~GraphicsComponent() {}

GraphicsComponent::GraphicsComponent(const glm::vec2 &position)
    : position_(position) {}

void GraphicsComponent::Update(const glm::vec2 &position) {
  position_ = position;
}

void GraphicsComponent::Draw() const {
  ci::gl::pushModelMatrix();
  ci::gl::translate(position_);
  Render();
  ci::gl::popModelMatrix();
}

const glm::vec2 &GraphicsComponent::GetPosition() const {
  return position_;
}

}
