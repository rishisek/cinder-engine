//
// Created by rishi on 25-04-2021.
//
#include <catch2/catch.hpp>
#include <game_engine/collision/circle_collider.h>
#include <game_engine/collision/box_collider.h>
#include <game_engine/collision/collider_mesh.h>

namespace game_engine {
TEST_CASE("Circle collider serialization",
          "[serialization][collision][game_engine]") {
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

TEST_CASE("Box collider serialization",
          "[serialization][collision][game_engine]") {
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

TEST_CASE("Collider mesh serialization",
          "[serialization][collision][game_engine]") {
  SECTION("Serialization") {
    ColliderMesh mesh;
    CircleCollider collider1(glm::vec2(1, 2), 3.0);
    mesh.AddCollider(new CircleCollider(glm::vec2(1, 2), 3.0));
    nlohmann::json json = mesh;
    REQUIRE(json[0] == collider1);
  }

  SECTION("Deserialization") {
    ColliderMesh mesh;
    CircleCollider collider1(glm::vec2(1, 2), 3.0);
    mesh.AddCollider(new CircleCollider(glm::vec2(1, 2), 3.0));
    nlohmann::json json = mesh;

    ColliderMesh mesh2(json);
    REQUIRE(collider1
                == *dynamic_cast<const CircleCollider *>(mesh2.GetColliders()[0]));
  }
}
}