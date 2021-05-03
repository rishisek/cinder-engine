//
// Created by rishi on 03-05-2021.
//
#include "ikaruga/app/background_manager.h"
#include <cinder/app/AppBase.h>

namespace ikaruga::app {
const ci::gl::Texture2dRef &BackgroundManager::GetOddBackground() {
  static ci::gl::Texture2dRef bg_texture_odd =
      ci::gl::Texture2d::create(loadImage(ci::app::loadAsset("space_bg_odd.png")));
  return bg_texture_odd;
}

const ci::gl::Texture2dRef &BackgroundManager::GetEvenBackground() {
  static ci::gl::Texture2dRef bg_texture_even =
      ci::gl::Texture2d::create(loadImage(ci::app::loadAsset("space_bg_even.png")));
  return bg_texture_even;
}

BackgroundManager::BackgroundManager() {
  background_positions_.resize(3);
  SetInitialState();
}

void BackgroundManager::SetInitialState() {
  background_positions_[0].y = 0;
  background_positions_[1].y =
      background_positions_[0].y + GetOddBackground()->getActualHeight();
  background_positions_[2].y =
      background_positions_[1].y + GetEvenBackground()->getActualHeight();
}

void BackgroundManager::Draw() {
  ci::gl::draw(GetOddBackground(), background_positions_[0]);
  ci::gl::draw(GetEvenBackground(), background_positions_[1]);
  ci::gl::draw(GetOddBackground(), background_positions_[2]);
}

void BackgroundManager::Update() {
  background_positions_[0].y--;
  background_positions_[1].y--;
  background_positions_[2].y--;
  if (background_positions_[1].y <= -cinder::app::getWindowHeight()) {
    SetInitialState();
  }
}
}