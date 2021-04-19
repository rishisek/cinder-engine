//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "cinder/Color.h"

namespace ikaruga {
class ProjectileType {
 public:
  ProjectileType(float radius,
                 const cinder::ColorT<float> &color,
                 int cooldown = 1);
  float GetRadius() const;
  const cinder::ColorT<float> &GetColor() const;
  int GetCurrentCooldown() const;
  void DecrementCurrentCooldown();
  void StartCooldown();
 private:
  float radius_;
  cinder::ColorT<float> color_;
  int cooldown_;
  int current_cooldown_;
};
}