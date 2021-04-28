//
// Created by rishi on 26-04-2021.
//
#pragma once
#include <game_engine/components/physics_component.h>

namespace ikaruga::objects::enemy {
class Enemy;
class EnemyType;

class EnemyFactory {
 public:
  static game_engine::PhysicsComponent *MakeEnemyPhysicsComponent(const nlohmann::json &json);
  static void AddEnemyType(EnemyType *enemy_type);
  static EnemyType *GetTypeByName(const std::string &enemy_type);
 private:
  static std::vector<EnemyType *> enemy_types_;
};
}