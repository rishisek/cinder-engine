//
// Created by rishi on 16-04-2021.
//
#pragma once
#include <game_engine/objects/character_object.h>
#include <ikaruga/core/objects/projectile/projectile_shooter.h>
#include <game_engine/game_world.h>
#include <game_engine/components/graphics_component.h>

namespace ikaruga::objects::enemy {
class EnemyType;
class EnemyFactory;
class Enemy
    : public projectile::ProjectileShooter {
 public:
  Enemy(game_engine::PhysicsComponent *physics_component,
        game_engine::GraphicsComponent *graphics_component,
        const std::string &type_id);
  void Update(game_engine::GameWorld &world) override;
  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;
  EnemyType *GetType() const;
  game_engine::GraphicsComponent *GetGraphicsComponent() const;
 private:
  game_engine::GraphicsComponent *graphics_component_;
  EnemyType *type_;
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