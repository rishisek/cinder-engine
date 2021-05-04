//
// Created by rishi on 20-04-2021.
//

#include <catch2/catch.hpp>
#include <ikaruga/core/objects/player/player.h>
#include <ikaruga/core/objects/player/player_physics_component.h>
#include <ikaruga/core/objects/player/player_input_component.h>

namespace ikaruga::objects::player {
std::vector<projectile::ProjectileType *> test_projectile_types = {
    new projectile::ProjectileType("type1", 5.0, cinder::Color("red"), 10),
    new projectile::ProjectileType("type2",
                                   10.0,
                                   cinder::Color("green"),
                                   10)
};

float CrossProduct(const glm::vec2 &v1, const glm::vec2 &v2) {
  return (v1.x * v2.y) - (v1.y * v2.x);
}

TEST_CASE("Player constructs properly") {
  Player *player =
      new Player(new PlayerPhysicsComponent(glm::vec2(5, 5), glm::vec2(2, 2)),
                 new PlayerInputComponent(), nullptr,
                 test_projectile_types, 0);
  REQUIRE(player->GetPhysicsComponent()->GetPosition() == glm::vec2(5, 5));
  REQUIRE(player->GetPhysicsComponent()->GetVelocity() == glm::vec2(2, 2));
  delete player;
}

TEST_CASE("Player shooting mechanics") {
  Player *player =
      new Player(new PlayerPhysicsComponent(glm::vec2(5, 5), glm::vec2(2, 2)),
                 new PlayerInputComponent(), nullptr,
                 test_projectile_types, 0);

  SECTION("Basic shooting") {
    projectile::Projectile *projectile = player->Shoot();
    REQUIRE(projectile->GetType() == test_projectile_types[0]);
    delete projectile;
  }

  SECTION("Checking if current projectile type is in cooldown") {
    projectile::Projectile *projectile = player->Shoot();
    REQUIRE(player->InCooldown());
    delete projectile;
  }

  SECTION("Type toggling") {
    player->ToggleProjectileType();
    projectile::Projectile *projectile = player->Shoot();
    REQUIRE(projectile->GetType() == test_projectile_types[1]);
    player->ToggleProjectileType();
    delete projectile;

    // TODO: debug variable reuse breakage
    projectile::Projectile *projectile2 = player->Shoot();
    REQUIRE(projectile2->GetType() == test_projectile_types[0]);
    delete projectile2;
  }

  SECTION("Aim tilting") {
    SECTION("No tilting i.e. along normal") {
      projectile::Projectile *projectile = player->Shoot();
      REQUIRE(CrossProduct(projectile->GetPhysicsComponent()->GetVelocity(),
                           glm::vec2(0, -M_PI)) == Approx(0).scale(1));
      delete projectile;
    }

    SECTION("Left tilting") {
      player->TiltAimLeft();
      projectile::Projectile *projectile = player->Shoot();
      REQUIRE(CrossProduct(projectile->GetPhysicsComponent()->GetVelocity(),
                           glm::vec2(0, -M_PI)) > 0);
      delete projectile;
    }

    SECTION("Right tilting") {
      player->TiltAimRight();
      projectile::Projectile *projectile = player->Shoot();
      REQUIRE(CrossProduct(projectile->GetPhysicsComponent()->GetVelocity(),
                           glm::vec2(0, -M_PI)) < 0);
      delete projectile;
    }
  }

  delete player;
}
}