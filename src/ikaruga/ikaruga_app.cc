//
// Created by rishi on 15-04-2021.
//

#include "ikaruga/ikaruga_app.h"

namespace ikaruga {

IkarugaApp::IkarugaApp() {

}

void IkarugaApp::draw() {
  AppBase::draw();
}

void IkarugaApp::mouseDown(ci::app::MouseEvent event) {
  AppBase::mouseDown(event);
}

void IkarugaApp::mouseDrag(ci::app::MouseEvent event) {
  AppBase::mouseDrag(event);
}

void IkarugaApp::keyDown(ci::app::KeyEvent event) {
  AppBase::keyDown(event);
}
}