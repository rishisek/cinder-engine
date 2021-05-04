//
// Created by rishi on 15-04-2021.
//

#include <ikaruga/app/ikaruga_app.h>
#include <interface/keyboard.h>
#include <ikaruga/app/health_bar.h>

namespace ikaruga::app {

IkarugaApp::IkarugaApp() {}

void IkarugaApp::draw() {
  ci::gl::clear(ci::Color("black"));
  background_manager_.Draw();

  ci::gl::pushModelMatrix();
  ci::gl::translate(glm::vec2(kLeftMargin, 0));
  game_instance_.Draw();
  ci::gl::popModelMatrix();

  ci::gl::pushModelMatrix();
  ci::gl::translate(glm::vec2(0, 0));
  HealthBar::Draw(game_instance_.GetPlayer()->GetMaxHealth(),
                  game_instance_.GetPlayer()->GetHealth());
  ci::gl::popModelMatrix();
}

void IkarugaApp::mouseDown(ci::app::MouseEvent event) {
}

void IkarugaApp::mouseDrag(ci::app::MouseEvent event) {
}

void IkarugaApp::keyDown(ci::app::KeyEvent event) {
  interface::Keyboard::Press(event.getCode());
}

void IkarugaApp::keyUp(ci::app::KeyEvent event) {
  interface::Keyboard::Release(event.getCode());
}

void IkarugaApp::setup() {
  ci::app::setWindowSize(
      static_cast<int>(game_instance_.GetWidth()) + kLeftMargin,
      static_cast<int>(game_instance_.GetHeight()));
  game_instance_.Setup();
}

void IkarugaApp::update() {
  background_manager_.Update();
  game_instance_.Update();
  interface::Keyboard::ReleaseAllToggles();
}
}