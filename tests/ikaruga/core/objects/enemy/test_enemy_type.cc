//
// Created by rishi on 26-04-2021.
//
#include <catch2/catch.hpp>
#include <ikaruga/core/objects/enemy/enemy_type.h>
#include <ikaruga/core/objects/enemy/movement/patterns.h>

namespace ikaruga::objects::enemy {
TEST_CASE("Enemy type serialization", "[serialization]") {
  SECTION("Serialization") {
    std::vector<projectile::ProjectileType> projectile_types = {
        projectile::ProjectileType(5, ci::Color("blue"), 7)
    };
    EnemyType enemy_type
        (10,
         2,
         movement::Pattern::kSineLine,
         projectile_types,
         ci::Color("red"));
    nlohmann::json json = enemy_type;
    REQUIRE(json["max_health"] == 10);
    REQUIRE(json["kill_score"] == 2);
    REQUIRE(json["pattern"] == movement::Pattern::kSineLine);
    REQUIRE(json["projectile_types"] == projectile_types);
    REQUIRE(json["color"] == ci::Color("red"));
  }

  SECTION("Deserialization") {
    std::vector<projectile::ProjectileType> projectile_types = {
        projectile::ProjectileType(5, ci::Color("blue"), 7)
    };
    EnemyType enemy_type1
        (10,
         2,
         movement::Pattern::kSineLine,
         projectile_types,
         ci::Color("red"));
    nlohmann::json json = enemy_type1;
    EnemyType enemy_type2 = json;
    REQUIRE(enemy_type1 == enemy_type2);
  }
}
}