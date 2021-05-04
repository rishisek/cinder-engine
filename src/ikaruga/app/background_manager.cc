//
// Created by rishi on 03-05-2021.
//
#include "ikaruga/app/background_manager.h"
#include <cinder/app/AppBase.h>
#include <cinder/Rand.h>

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
  ci::gl::color(0.65f, 0.65f, 0.65f);
  ci::gl::draw(GetOddBackground(), background_positions_[0]);
  ci::gl::draw(GetEvenBackground(), background_positions_[1]);
  ci::gl::draw(GetOddBackground(), background_positions_[2]);
}

void BackgroundManager::Update() {
  UpdateVerticalScroll();
  ShiftRandomHorizontal();
}

void BackgroundManager::UpdateVerticalScroll() {
  background_positions_[0].y--;
  background_positions_[1].y--;
  background_positions_[2].y--;
  if (background_positions_[1].y <= -GetEvenBackground()->getHeight()) {
    SetInitialState();
  }
}

void BackgroundManager::ShiftRandomHorizontal() {
  float min_bg_width = fmin(float(GetOddBackground()->getWidth()),
                            float(GetEvenBackground()->getWidth()));
  ci::Rand::randomize();
  float dx_step = ci::Rand::randFloat(0.05f);

  int a = abs(ci::Rand::randInt());
  int b = ci::Rand::randInt(a);
  int c = ci::Rand::randInt(b);
  float dx = (a % b == c ? 1 : -1) * dx_step;

  if (background_positions_[0].x + dx <= 0
      && background_positions_[0].x + dx + min_bg_width
          >= ci::app::getWindowWidth()) {
    background_positions_[0].x += dx;
    background_positions_[1].x += dx;
    background_positions_[2].x += dx;
  }
}
}