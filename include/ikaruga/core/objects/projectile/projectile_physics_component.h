//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/components/physics_component.h>

namespace ikaruga::objects::projectile {
class ProjectilePhysicsComponent : public game_engine::PhysicsComponent {
 public:
  void Update() override;
  void receive(int message) override;
  ProjectilePhysicsComponent(const glm::vec2 &position,
                             const glm::vec2 &velocity,
                             double radius);
 private:
  double radius_;
};
}
