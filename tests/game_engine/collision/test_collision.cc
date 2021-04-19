//
// Created by rishi on 19-04-2021.
//

#include <catch2/catch.hpp>
#include <game_engine/collision/circle_collider.h>

namespace game_engine {
TEST_CASE("Collision", "[game_engine][collision][physics]") {
  SECTION("Circle and Circle") {
    Collider *circle1;
    Collider *circle2;

    SECTION("Circles overlap") {
      circle1 = new CircleCollider(glm::vec2(0, 0), 5);
      circle2 = new CircleCollider(glm::vec2(0, 0), 5);
      REQUIRE(circle1->IsCollision(*circle2));
      REQUIRE(circle2->IsCollision(*circle1));
      delete circle1;
      delete circle2;
    }

    SECTION("Circles touching at circumference") {
      // Pythagorean triangle
      circle1 = new CircleCollider(glm::vec2(7, 0), 12.5);
      circle2 = new CircleCollider(glm::vec2(0, 24), 12.5);
      REQUIRE(circle1->IsCollision(*circle2));
      REQUIRE(circle2->IsCollision(*circle1));
      delete circle1;
      delete circle2;
    }

    SECTION("Circles not in contact") {
      circle1 = new CircleCollider(glm::vec2(0, 0), 5);
      circle2 = new CircleCollider(glm::vec2(20, 20), 5);
      REQUIRE_FALSE(circle1->IsCollision(*circle2));
      REQUIRE_FALSE(circle2->IsCollision(*circle1));
      delete circle1;
      delete circle2;
    }
  }
}
}