//
// Created by rishi on 15-04-2021.
//

#include "ikaruga/app/ikaruga_app.h"
#include <interface/keyboard.h>

namespace ikaruga::app {

IkarugaApp::IkarugaApp() {}

void IkarugaApp::draw() {
  ci::gl::clear(ci::Color("black"));
  background_manager_.Draw();
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
  ci::app::setWindowSize(static_cast<int>(400),
                         static_cast<int>(600));
}

void IkarugaApp::update() {
  background_manager_.Update();
}
}