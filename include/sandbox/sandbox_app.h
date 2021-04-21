//
// Created by rishi on 15-04-2021.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <ikaruga/core/objects/player/player.h>
#include <ikaruga/core/world/world.h>

namespace sandbox {
using namespace ikaruga::objects::player;
class Sandbox : public ci::app::App {
 public:
  Sandbox();

  void setup() override;
  void draw() override;
  void update() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;
  void keyUp(ci::app::KeyEvent event) override;

 private:
  const double kWindowSize = 875;
  Player player_;
  ikaruga::world::World world_;
};
}