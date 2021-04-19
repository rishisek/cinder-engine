//
// Created by rishi on 17-04-2021.
//
#pragma once

#include "circle_collider.h"
#include "box_collider.h"
namespace game_engine {
class CollisionUtils {
 public:
  static bool IsCollision(CircleCollider const *circle, BoxCollider const *box);
  static bool IsCollision(BoxCollider const *box, CircleCollider const *circle);
  static bool IsCollision(CircleCollider const *circle1,
                          CircleCollider const *circle2);
};
}
