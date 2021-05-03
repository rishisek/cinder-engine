//
// Created by rishi on 03-05-2021.
//
#pragma once
#include <cinder/gl/gl.h>

namespace ikaruga::app {
class BackgroundManager {
 public:
  BackgroundManager();
  void SetInitialState();
  void Draw();
  void Update();
 private:
  const ci::gl::Texture2dRef &GetOddBackground();
  const ci::gl::Texture2dRef &GetEvenBackground();
  std::vector<glm::vec2> background_positions_;
};
}