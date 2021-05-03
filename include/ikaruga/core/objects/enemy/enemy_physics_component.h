//
// Created by rishi on 22-04-2021.
//
#pragma once

#include <game_engine/components/physics_component.h>
#include <ikaruga/core/objects/enemy/movement/movement_strategy.h>

namespace ikaruga::objects::enemy {
class EnemyPhysicsComponent : public game_engine::PhysicsComponent {
 public:
  EnemyPhysicsComponent(const glm::vec2 &position,
                        const glm::vec2 &velocity,
                        game_engine::ColliderMesh &&collider_mesh,
                        movement::MovementStrategy *movement_strategy);
  void Update() override;
  void receive(int message) override;
 protected:
  movement::MovementStrategy *movement_strategy_;
};
}