//
// Created by rishi on 26-04-2021.
//
#include <ikaruga/core/objects/enemy/enemy_factory.h>
#include <serialization_utils/vec2_json.h>
#include <ikaruga/core/objects/enemy/movement/sine_line_movement_physics_component.h>
#include <ikaruga/core/objects/enemy/movement/sine_loop_movement_physics_component.h>

namespace ikaruga::objects::enemy {
game_engine::PhysicsComponent *EnemyFactory::MakeEnemyPhysicsComponent(const nlohmann::json &json) {
  using namespace movement;
  glm::vec2 position = json.at("physics_component").at("position");
  glm::vec2 velocity = json.at("physics_component").at("velocity");

  switch (json.at("enemy_type").at("pattern").get<Pattern>()) {
    case kSineLine:
      return new SineLineMovementPhysicsComponent(position,
                                                  velocity,
                                                  json.at("physics_component").at(
                                                      "collider_mesh"));
    case kSineLoop:
      return new SineLoopMovementPhysicsComponent(position,
                                                  velocity,
                                                  json.at("physics_component").at(
                                                      "collider_mesh"));
    default:
      return nullptr;
  }
}
}

namespace nlohmann {
ikaruga::objects::enemy::Enemy adl_serializer<ikaruga::objects::enemy::Enemy>::from_json(
    const json &j) {
  return {ikaruga::objects::enemy::EnemyFactory::MakeEnemyPhysicsComponent(j),
          j.at("enemy_type")};
}

void adl_serializer<ikaruga::objects::enemy::Enemy>::to_json(json &j,
                                                             ikaruga::objects::enemy::Enemy t) {
  t.Serialize(j);
}
}