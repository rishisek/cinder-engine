//
// Created by rishi on 15-04-2021.
//

#include "ikaruga/app/ikaruga_app.h"

namespace ikaruga {

IkarugaApp::IkarugaApp() {}

void IkarugaApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
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
}

void IkarugaApp::update() {
}
}