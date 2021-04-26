//
// Created by rishi on 26-04-2021.
//
#pragma once
#include <ikaruga/core/objects/enemy/enemy.h>

namespace ikaruga::objects::enemy {
class EnemyFactory {
 public:
  static game_engine::PhysicsComponent *MakeEnemyPhysicsComponent(const nlohmann::json &json);
};
}

namespace nlohmann {
template<>
struct adl_serializer<ikaruga::objects::enemy::Enemy> {
  // note: the return type is no longer 'void', and the method only takes
  // one argument
  static ikaruga::objects::enemy::Enemy from_json(const json &j);

  // Here's the catch! You must provide a to_json method! Otherwise you
  // will not be able to convert ikaruga::objects::enemy::Enemy to json, since you fully
  // specialized adl_serializer on that type
  static void to_json(json &j, ikaruga::objects::enemy::Enemy t);
};
}