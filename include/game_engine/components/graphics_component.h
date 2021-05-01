//
// Created by rishi on 01-05-2021.
//

#pragma once
#include <game_engine/components/component.h>
#include <glm/vec2.hpp>

namespace game_engine {
class GraphicsComponent : public Component {
 public:
  virtual ~GraphicsComponent() = 0;
  virtual void Draw() const = 0;
  virtual void Update(const glm::vec2 &position);
 protected:
  GraphicsComponent(const glm::vec2 &position);
  glm::vec2 position_;
};
}