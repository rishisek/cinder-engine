//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/json_serializable.h>
#include <serialization_utils/cinder_color_json.h>
#include "cinder/Color.h"

namespace ikaruga::objects::projectile {
class ProjectileType : public game_engine::JsonSerializable {
 public:
  ProjectileType(float radius,
                 const cinder::ColorT<float> &color,
                 int cooldown = 1);

  float GetRadius() const;
  const cinder::ColorT<float> &GetColor() const;
  int GetCooldown() const;

  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;

  bool operator==(ProjectileType const &other) const;
 private:
  float radius_;
  cinder::ColorT<float> color_;
  int cooldown_;
};
}

namespace nlohmann {
template<>
struct adl_serializer<ikaruga::objects::projectile::ProjectileType> {
  // note: the return type is no longer 'void', and the method only takes
  // one argument
  static ikaruga::objects::projectile::ProjectileType from_json(const json &j);

  // Here's the catch! You must provide a to_json method! Otherwise you
  // will not be able to convert ikaruga::objects::projectile::ProjectileType to json, since you fully
  // specialized adl_serializer on that type
  static void to_json(json &j, ikaruga::objects::projectile::ProjectileType t);
};
}