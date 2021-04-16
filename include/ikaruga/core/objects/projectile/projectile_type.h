//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "cinder/Color.h"

namespace ikaruga {
class ProjectileType {
 public:
  ProjectileType(float radius, const cinder::ColorT<float> &color);
  float GetRadius() const;
  const cinder::ColorT<float> &GetColor() const;
 private:
  float radius_;
  cinder::ColorT<float> color_;  
};
}