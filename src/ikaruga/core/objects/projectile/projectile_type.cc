//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/projectile/projectile_type.h"

namespace ikaruga {
ProjectileType::ProjectileType(float radius, const cinder::ColorT<float> &color)
    : radius_(radius), color_(color) {}

float ProjectileType::GetRadius() const {
  return radius_;
}

const cinder::ColorT<float> &ProjectileType::GetColor() const {
  return color_;
}
}