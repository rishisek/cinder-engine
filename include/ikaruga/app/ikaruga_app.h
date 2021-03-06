//
// Created by rishi on 15-04-2021.
//

#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <ikaruga/app/background_manager.h>
#include <ikaruga/game/game_instance.h>

namespace ikaruga::app {
class IkarugaApp : public ci::app::App {
 public:
  IkarugaApp();

  void setup() override;
  void draw() override;
  void update() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;
  void keyUp(ci::app::KeyEvent event) override;

 private:
  const int kLeftMargin = 100;
  BackgroundManager background_manager_;
  ikaruga::game::GameInstance game_instance_;
};
}