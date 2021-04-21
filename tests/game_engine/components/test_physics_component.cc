//
// Created by rishi on 18-04-2021.
//

#include <catch2/catch.hpp>
#include <game_engine/components/physics_component.h>

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

 protected:
  void UpdateColliderMesh() override {}
};

TEST_CASE("Physics component", "[game engine][physics]") {
  SECTION("Constructors") {
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

  SECTION("Position updating") {
    PhysicsComponent
        *component = new DummyPhysics(glm::vec2(1, 1), glm::vec2(1, 1));
    component->Update();
    REQUIRE(component->GetPosition() == glm::vec2(2, 2));
    REQUIRE(component->GetVelocity() == glm::vec2(1, 1));
    delete component;
  }

  SECTION("Collision checking") {
  }
}
}