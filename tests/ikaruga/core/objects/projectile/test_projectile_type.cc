//
// Created by rishi on 20-04-2021.
//

#include <catch2/catch.hpp>
#include <ikaruga/core/objects/projectile/projectile_type.h>

namespace ikaruga::objects::projectile {
TEST_CASE("ProjectileType constructs properly") {
  ProjectileType type(5.0, cinder::Color("red"), 5);
  REQUIRE(type.GetRadius() == Approx(5.0));
  REQUIRE(type.GetColor() == cinder::Color("red"));
  REQUIRE(type.GetCurrentCooldown() == 0);
}

TEST_CASE("ProjectileType cooldown cycle") {
  ProjectileType type(5.0, cinder::Color("red"), 1);

  type.StartCooldown();

  SECTION("Start cooldown cycle") {
    REQUIRE(type.GetCurrentCooldown() == 1);
  }

  type.DecrementCurrentCooldown();
  SECTION("Decrement cooldown") {
    REQUIRE(type.GetCurrentCooldown() == 0);
  }

  type.DecrementCurrentCooldown();
  SECTION("Stop decrement at cooldown zero") {
    REQUIRE(type.GetCurrentCooldown() == 0);
  }
}
}