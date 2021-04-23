//
// Created by rishi on 19-04-2021.
//

#include <catch2/catch.hpp>
#include <game_engine/collision/circle_collider.h>
#include <game_engine/collision/box_collider.h>
#include <game_engine/collision/collider_mesh.h>

namespace game_engine {
TEST_CASE("Collider mesh", "[game_engine][collision][physics]") {
  ColliderMesh mesh1;
  ColliderMesh mesh2;

  SECTION("Collider addition") {
    SECTION("Empty mesh") {
      REQUIRE(mesh1.GetColliders().size() == 0);
    }

    SECTION("Non-empty mesh") {
      mesh1.AddCollider(new CircleCollider(glm::vec2(0, 0), 5));
      REQUIRE(mesh1.GetColliders().size() == 1);
    }
  }

  SECTION("Collision checking") {
    SECTION("Empty mesh with empty mesh") {
      REQUIRE_FALSE(mesh1.IsCollision(mesh2));
      REQUIRE_FALSE(mesh2.IsCollision(mesh1));
    }

    SECTION("Empty mesh with non-empty mesh") {
      mesh1.AddCollider(new CircleCollider(glm::vec2(0, 0), 5));
      REQUIRE_FALSE(mesh1.IsCollision(mesh2));
      REQUIRE_FALSE(mesh2.IsCollision(mesh1));
    }

    SECTION("Non-empty mesh with non-empty mesh") {
      mesh1.AddCollider(new CircleCollider(glm::vec2(0, 0), 5));
      mesh2.AddCollider(new BoxCollider(glm::vec2(0, 0), 5, 4));
      REQUIRE(mesh1.IsCollision(mesh2));
      REQUIRE(mesh2.IsCollision(mesh1));
    }
  }
}
}