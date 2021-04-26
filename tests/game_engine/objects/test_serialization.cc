//
// Created by rishi on 25-04-2021.
//
#include <catch2/catch.hpp>
#include <game_engine/components/physics_component.h>
#include <game_engine/objects/character_object.h>

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

class DummyCharacter : public CharacterObject {
 public:
  DummyCharacter(DummyPhysics *p_physics) : CharacterObject(p_physics) {}
};

TEST_CASE("CharacterObject serialization") {
  CharacterObject *character = new DummyCharacter(new DummyPhysics());
  nlohmann::json json = *character;
  REQUIRE(json.at("max_health") == 1);
  REQUIRE(json.at("health") == 0);
  delete character;
}
}