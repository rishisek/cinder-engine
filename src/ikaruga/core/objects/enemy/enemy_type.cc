//
// Created by rishi on 16-04-2021.
//

#include <vector>
#include "ikaruga/core/objects/enemy/enemy_type.h"

namespace ikaruga::objects::enemy {
int EnemyType::GetMaxHealth() const {
  return max_health_;
}

const std::vector<projectile::ProjectileType> &EnemyType::GetProjectileTypes() const {
  return projectile_types_;
}

EnemyType::EnemyType(const std::string &id,
                     int max_health,
                     int kill_score,
                     ikaruga::objects::enemy::movement::Pattern pattern,
                     const std::vector<projectile::ProjectileType> &projectile_types,
                     const ci::Color &color)
    : id_(id), max_health_(max_health),
      kill_score_(kill_score),
      pattern_(pattern),
      projectile_types_(projectile_types),
      color_(color) {}

const ci::ColorT<float> &EnemyType::GetColor() const {
  return color_;
}

void EnemyType::Serialize(nlohmann::json &json) const {
  json["id"] = id_;
  json["max_health"] = max_health_;
  json["kill_score"] = kill_score_;
  json["pattern"] = pattern_;
  json["projectile_types"] = projectile_types_;
  json["color"] = color_;
}

void EnemyType::Deserialize(const nlohmann::json &json) {
  id_ = json["id"];
  max_health_ = json["max_health"];
  kill_score_ = json["kill_score"];
  pattern_ = json["pattern"];
  projectile_types_ =
      json["projectile_types"].get<std::vector<projectile::ProjectileType>>();
  color_ = json["color"];
}

bool EnemyType::operator==(const EnemyType &rhs) const {
  return id_ == rhs.id_;
}

bool EnemyType::operator!=(const EnemyType &rhs) const {
  return !(rhs == *this);
}

int EnemyType::GetKillScore() const {
  return kill_score_;
}

const std::string &EnemyType::GetId() const {
  return id_;
}

movement::Pattern EnemyType::GetPattern() const {
  return pattern_;
}
}

namespace nlohmann {
ikaruga::objects::enemy::EnemyType adl_serializer<ikaruga::objects::enemy::EnemyType>::from_json(
    const json &j) {
  return {j.at("id"), j.at("max_health"), j.at("kill_score"), j.at("pattern"),
          j.at("projectile_types"), j.at("color")};
}

void adl_serializer<ikaruga::objects::enemy::EnemyType>::to_json(json &j,
                                                                 ikaruga::objects::enemy::EnemyType t) {
  t.Serialize(j);
}
}