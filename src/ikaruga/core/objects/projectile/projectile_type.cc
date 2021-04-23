//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/projectile/projectile_type.h"

namespace ikaruga::objects::projectile {
ProjectileType::ProjectileType(float radius,
                               const cinder::ColorT<float> &color,
                               int cooldown)
    : radius_(radius),
      color_(color),
      cooldown_(cooldown) {}

float ProjectileType::GetRadius() const {
  return radius_;
}

const cinder::ColorT<float> &ProjectileType::GetColor() const {
  return color_;
}

int ProjectileType::GetCurrentCooldown() const {
  return current_cooldown_;
}

void ProjectileType::DecrementCurrentCooldown() {
  current_cooldown_--;
  if (current_cooldown_ <= 0) {
    current_cooldown_ = 0;
  }
}

void ProjectileType::StartCooldown() {
  current_cooldown_ = cooldown_;
}

bool ProjectileType::operator==(const ProjectileType &other) const {
  return radius_ == other.radius_ && color_ == other.color_
      && cooldown_ == other.cooldown_;
}
}