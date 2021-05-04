//
// Created by rishi on 20-04-2021.
//

#include <catch2/catch.hpp>
#include <ikaruga/core/objects/projectile/projectile_type.h>

namespace ikaruga::objects::projectile {
TEST_CASE("ProjectileType constructs properly") {
  ProjectileType type("type1", 5.0, cinder::Color("red"), 5);
  REQUIRE(type.GetRadius() == Approx(5.0));
  REQUIRE(type.GetColor() == cinder::Color("red"));
}

TEST_CASE("Projectile type serialization", "[serialization]") {
  SECTION("Serialization") {
    ProjectileType type("type1", 5.0, cinder::Color("red"), 5);
    nlohmann::json json = type;
    REQUIRE(json["radius"] == Approx(5.0));
    REQUIRE(json["color"] == cinder::Color("red"));
    REQUIRE(json["cooldown"] == 5);
  }

  SECTION("Deserialization") {
    ProjectileType type1("type1", 5.0, cinder::Color("red"), 5);
    nlohmann::json json = type1;
    ProjectileType type2 = json;
    REQUIRE(type1 == type2);
  }
}
}