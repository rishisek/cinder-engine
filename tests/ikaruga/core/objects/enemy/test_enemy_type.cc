//
// Created by rishi on 26-04-2021.
//
#include <catch2/catch.hpp>
#include <serialization_utils/vec2_json.h>
#include <ikaruga/core/objects/enemy/enemy_type.h>
#include <ikaruga/core/objects/enemy/movement/patterns.h>
#include <ikaruga/core/objects/projectile/projectile_factory.h>

namespace ikaruga::objects::enemy {
TEST_CASE("Enemy type serialization", "[serialization]") {
  SECTION("Serialization") {
    std::vector<projectile::ProjectileType *> projectile_types = {
        new projectile::ProjectileType("type1", 5, ci::Color("blue"), 7, 1)
    };
    EnemyType enemy_type
        ("id", 10,
         2,
         movement::Pattern::kSineLine,
         projectile_types,
         ci::Color("red"),
         glm::vec2(1, 2));
    nlohmann::json json = enemy_type;
    REQUIRE(json["max_health"] == 10);
    REQUIRE(json["kill_score"] == 2);
    REQUIRE(json["pattern"] == movement::Pattern::kSineLine);
    REQUIRE(json["projectile_types"] == std::vector<std::string>{"type1"});
    REQUIRE(json["color"] == ci::Color("red"));
    REQUIRE(json["shoot_offset"] == glm::vec2(1, 2));
  }

  SECTION("Deserialization") {
    projectile::ProjectileFactory::AddProjectileType(new projectile::ProjectileType(
        "type1",
        5,
        ci::Color("blue"),
        7,
        1));
    std::vector<projectile::ProjectileType *> projectile_types =
        projectile::ProjectileFactory::GetTypesById({"type1"});
    EnemyType enemy_type1
        ("id", 10,
         2,
         movement::Pattern::kSineLine,
         projectile_types,
         ci::Color("red"),
         glm::vec2(1, 2));
    nlohmann::json json = enemy_type1;
    EnemyType enemy_type2 = json;
    REQUIRE(enemy_type1 == enemy_type2);
  }
}
}