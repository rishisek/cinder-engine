//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/projectile/projectile_type.h>
#include <ikaruga/core/objects/enemy/movement/patterns.h>
#include <game_engine/json_serializable.h>
#include <serialization_utils/cinder_color_json.h>

namespace ikaruga::objects::enemy {
class EnemyType : public game_engine::JsonSerializable {
 public:
  EnemyType(int max_health,
            int kill_score,
            ikaruga::objects::enemy::movement::Pattern pattern,
            const std::vector<projectile::ProjectileType> &projectile_types,
            const ci::Color &color);

  bool operator==(const EnemyType &rhs) const;
  bool operator!=(const EnemyType &rhs) const;

  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;

  int GetMaxHealth() const;
  int GetKillScore() const;
  const std::vector<projectile::ProjectileType> &GetProjectileTypes() const;
  const ci::ColorT<float> &GetColor() const;
 private:
  int max_health_;
  int kill_score_;
  movement::Pattern pattern_;
  std::vector<projectile::ProjectileType> projectile_types_;
  ci::ColorT<float> color_;
};
}

namespace nlohmann {
template<>
struct adl_serializer<ikaruga::objects::enemy::EnemyType> {
  // note: the return type is no longer 'void', and the method only takes
  // one argument
  static ikaruga::objects::enemy::EnemyType from_json(const json &j);

  // Here's the catch! You must provide a to_json method! Otherwise you
  // will not be able to convert ikaruga::objects::enemy::EnemyType to json, since you fully
  // specialized adl_serializer on that type
  static void to_json(json &j, ikaruga::objects::enemy::EnemyType t);
};
}