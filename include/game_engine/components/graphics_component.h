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
  void Draw() const;
  virtual void Update(const glm::vec2 &position);
  const glm::vec2 &GetPosition() const;
 protected:
  GraphicsComponent(const glm::vec2 &position);
  virtual void Render() const = 0;
  glm::vec2 position_;
};
}