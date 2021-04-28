//
// Created by rishi on 26-04-2021.
//
#include <ikaruga/core/objects/enemy/enemy_factory.h>
#include <ikaruga/core/objects/enemy/enemy.h>
#include <ikaruga/core/objects/enemy/enemy_type.h>
#include <serialization_utils/vec2_json.h>
#include <ikaruga/core/objects/enemy/movement/sine_line_movement_physics_component.h>
#include <ikaruga/core/objects/enemy/movement/sine_loop_movement_physics_component.h>

namespace ikaruga::objects::enemy {
std::vector<EnemyType *> EnemyFactory::enemy_types_;

game_engine::PhysicsComponent *EnemyFactory::MakeEnemyPhysicsComponent(const nlohmann::json &json) {
  using namespace movement;
  glm::vec2 position = json.at("physics_component").at("position");
  glm::vec2 velocity = json.at("physics_component").at("velocity");

  switch (GetTypeByName(json.at("enemy_type"))->GetPattern()) {
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

void EnemyFactory::AddEnemyType(EnemyType *enemy_type) {
  enemy_types_.push_back(enemy_type);
}

EnemyType *EnemyFactory::GetTypeByName(const std::string &enemy_type_id) {
  auto it = find_if(enemy_types_.begin(),
                    enemy_types_.end(),
                    [&](const EnemyType *const &enemy_type) {
                      return enemy_type->GetId() == enemy_type_id;
                    });
  return *it;
}
}