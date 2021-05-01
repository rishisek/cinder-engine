//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/objects/enemy/enemy.h>
#include <ikaruga/core/objects/enemy/enemy_factory.h>
#include <game_engine/components/physics_component.h>
#include <ikaruga/core/objects/enemy/enemy_type.h>

namespace ikaruga::objects::enemy {
using projectile::ProjectileShooter;
using projectile::ProjectileType;

Enemy::Enemy(game_engine::PhysicsComponent *physics_component,
             const std::string &type_id)
    : ProjectileShooter(physics_component,
                        EnemyFactory::GetTypeByName(type_id)->GetProjectileTypes(),
                        EnemyFactory::GetTypeByName(type_id)->GetShootOffset()),
      type_(EnemyFactory::GetTypeByName(type_id)) {}

void Enemy::Update(game_engine::GameWorld &world) {
  physics_component_->Update();
}

void Enemy::Serialize(nlohmann::json &json) const {
  CharacterObject::Serialize(json);
  json["enemy_type"] = type_->GetId();
}

void Enemy::Deserialize(const nlohmann::json &json) {
  CharacterObject::Deserialize(json);
  type_ = EnemyFactory::GetTypeByName(json["enemy_type"]);
}

EnemyType *Enemy::GetType() const {
  return type_;
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