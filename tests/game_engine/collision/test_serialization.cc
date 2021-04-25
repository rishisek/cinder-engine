//
// Created by rishi on 25-04-2021.
//
#include <catch2/catch.hpp>
#include <game_engine/collision/circle_collider.h>
#include <game_engine/collision/box_collider.h>
#include <game_engine/collision/collider_mesh.h>

namespace game_engine {
TEST_CASE("CircleCollider serialization", "[serialization]") {
  SECTION("Serialization") {
    CircleCollider collider(glm::vec2(1, 2), 3);
    nlohmann::json json = collider;
    REQUIRE(json.at("position") == glm::vec2(1, 2));
    REQUIRE(json.at("radius") == 3);
    REQUIRE(json == collider);
  }

  SECTION("Deserialization") {
    CircleCollider collider1(glm::vec2(1, 2), 3);
    nlohmann::json json = collider1;
    CircleCollider collider2 = json;
    REQUIRE(collider1 == collider2);
  }
}

TEST_CASE("BoxCollider serialization", "[serialization]") {
  SECTION("Serialization") {
    BoxCollider collider(glm::vec2(1, 2), 3, 4);
    nlohmann::json json = collider;
    REQUIRE(json.at("position") == glm::vec2(1, 2));
    REQUIRE(json.at("width") == 3);
    REQUIRE(json.at("height") == 4);
  }

  SECTION("Deserialization") {
    BoxCollider collider1(glm::vec2(1, 2), 3, 4);
    nlohmann::json json = collider1;
    BoxCollider collider2 = json;
    REQUIRE(collider1 == collider2);
  }
}
}