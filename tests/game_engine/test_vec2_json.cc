//
// Created by rishi on 25-04-2021.
//
#include <catch2/catch.hpp>
#include <nlohmann/json.hpp>
#include <glm/vec2.hpp>
#include <serialization_utils/vec2_json.h>

TEST_CASE("glm::vec2 serialization", "[serialization]") {
  SECTION("Serialization") {
    glm::vec2 vec(1, 2);
    nlohmann::json json = vec;
    REQUIRE(json.at("x") == 1);
    REQUIRE(json.at("y") == 2);
  }

  SECTION("Deserialization") {
    glm::vec2 vec1(1, 2);
    nlohmann::json json = vec1;

    glm::vec2 vec2 = json.get<glm::vec2>();
    REQUIRE(vec1 == vec2);
  }
}