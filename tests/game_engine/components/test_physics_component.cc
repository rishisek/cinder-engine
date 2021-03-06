//
// Created by rishi on 18-04-2021.
//

#include <catch2/catch.hpp>
#include <game_engine/components/physics_component.h>
#include <serialization_utils/vec2_json.h>
#include <game_engine/collision/circle_collider.h>

namespace game_engine {
class DummyPhysics : public PhysicsComponent {
 public:
  DummyPhysics(const glm::vec2 &position = glm::vec2(),
               const glm::vec2 &velocity = glm::vec2())
      : PhysicsComponent(position, velocity) {}

  void receive(int message) override {}

  void Update() override {
    UpdatePosition();
  }
};

TEST_CASE("Physics component constructors", "[game engine][physics]") {
  SECTION("Default") {
    PhysicsComponent *component = new DummyPhysics();
    REQUIRE(component->GetPosition() == glm::vec2());
    REQUIRE(component->GetVelocity() == glm::vec2());
    delete component;
  }

  SECTION("Position parameter") {
    PhysicsComponent *component = new DummyPhysics(glm::vec2(1, 1));
    REQUIRE(component->GetPosition() == glm::vec2(1, 1));
    REQUIRE(component->GetVelocity() == glm::vec2());
    delete component;
  }

  SECTION("Position and velocity parameters") {
    PhysicsComponent
        *component = new DummyPhysics(glm::vec2(1, 1), glm::vec2(1, 1));
    REQUIRE(component->GetPosition() == glm::vec2(1, 1));
    REQUIRE(component->GetVelocity() == glm::vec2(1, 1));
    delete component;
  }
}

TEST_CASE("Physics component behavior", "[game engine][physics]") {
  SECTION("Position updating") {
    PhysicsComponent
        *component = new DummyPhysics(glm::vec2(1, 1), glm::vec2(1, 1));
    component->Update();
    REQUIRE(component->GetPosition() == glm::vec2(2, 2));
    REQUIRE(component->GetVelocity() == glm::vec2(1, 1));
    delete component;
  }

  SECTION("Collision checking") {
    PhysicsComponent
        *component1 = new DummyPhysics(glm::vec2(1, 1), glm::vec2(1, 1));
    PhysicsComponent
        *component2 = new DummyPhysics(glm::vec2(1, 1), glm::vec2(1, 1));
    component1->AddCollider(new CircleCollider(glm::vec2(1, 1), 5));
    component2->AddCollider(new CircleCollider(glm::vec2(7, 1), 5));
    REQUIRE(component1->Collides(component2));
    delete component1;
    delete component2;
  }
}

TEST_CASE("Physics component serialization", "[serialization][game_engine]") {
  PhysicsComponent
      *component = new DummyPhysics(glm::vec2(1, 2), glm::vec2(3, 4));
  nlohmann::json json = *component;
  REQUIRE(json.at("position") == glm::vec2(1, 2));
  REQUIRE(json.at("velocity") == glm::vec2(3, 4));
  delete component;
}
}