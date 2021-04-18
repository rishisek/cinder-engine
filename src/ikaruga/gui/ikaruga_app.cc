//
// Created by rishi on 15-04-2021.
//

#include "ikaruga/gui/ikaruga_app.h"

namespace ikaruga {

IkarugaApp::IkarugaApp()
    : player_(
    new PlayerPhysicsComponent(glm::vec2(300, 300), glm::vec2(0, 0)),
    new PlayerInputComponent(),
    std::vector<ProjectileType>{
        ProjectileType(5, ci::Color(0, 1, 0), 50),
        ProjectileType(5, ci::Color(1, 0, 0), 25)
    }), world_(new WorldPhysicsComponent()) {}

void IkarugaApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
}

void IkarugaApp::mouseDown(ci::app::MouseEvent event) {
}

void IkarugaApp::mouseDrag(ci::app::MouseEvent event) {
}

void IkarugaApp::keyDown(ci::app::KeyEvent event) {
}

void IkarugaApp::setup() {
}

void IkarugaApp::update() {
}
}