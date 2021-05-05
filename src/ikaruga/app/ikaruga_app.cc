//
// Created by rishi on 15-04-2021.
//

#include <ikaruga/app/ikaruga_app.h>
#include <interface/keyboard.h>
#include <ikaruga/app/health_bar.h>

namespace ikaruga::app {

IkarugaApp::IkarugaApp() {}

void IkarugaApp::draw() {
  static ci::Font font("Impact", 30);
  ci::gl::clear(ci::Color("black"));
  background_manager_.Draw();

  if (!game_instance_.IsEnded()) {
    ci::gl::pushModelMatrix();
    ci::gl::translate(glm::vec2(kLeftMargin, 0));
    game_instance_.Draw();
    ci::gl::popModelMatrix();

    ci::gl::pushModelMatrix();
    ci::gl::translate(glm::vec2(0, getWindowHeight() - 300));
    HealthBar::Draw(game_instance_.GetPlayer()->GetMaxHealth(),
                    game_instance_.GetPlayer()->GetHealth());
    ci::gl::popModelMatrix();

    ci::gl::drawString(std::to_string(game_instance_.GetPlayer()->GetScore()),
                       glm::vec2(10, 200),
                       ci::Color("white"),
                       font);
  } else {
    if (game_instance_.IsPlayerWin()) {
      ci::gl::drawStringCentered("You Win!",
                                 getWindowCenter(),
                                 ci::Color("white"),
                                 font);
    }
    if (game_instance_.IsPlayerLoss()) {
      ci::gl::drawStringCentered("You Lose.",
                                 getWindowCenter(),
                                 ci::Color("white"),
                                 font);
    }
  }
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
  if (!game_instance_.IsEnded()) {
    game_instance_.Update();
    interface::Keyboard::ReleaseAllToggles();
  }

}
}