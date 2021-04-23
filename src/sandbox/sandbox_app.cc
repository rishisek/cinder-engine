//
// Created by rishi on 15-04-2021.
//

#include <sandbox/sandbox_app.h>
#include <ikaruga/core/objects/player/player_physics_component.h>
#include <ikaruga/core/objects/player/player_input_component.h>
#include <interface/keyboard.h>

namespace sandbox {

Sandbox::Sandbox() {}

void Sandbox::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  game_instance_.Draw();
}

void Sandbox::mouseDown(ci::app::MouseEvent event) {
}

void Sandbox::mouseDrag(ci::app::MouseEvent event) {
}

void Sandbox::keyDown(ci::app::KeyEvent event) {
  interface::Keyboard::Press(event.getCode());
}

void Sandbox::keyUp(ci::app::KeyEvent event) {
  interface::Keyboard::Release(event.getCode());
}

void Sandbox::setup() {
  ci::app::setWindowSize(int(game_instance_.GetWidth()), kWindowSize);
  game_instance_.Setup();
}

void Sandbox::update() {
  game_instance_.Update();
  interface::Keyboard::ReleaseAllToggles();
}
}