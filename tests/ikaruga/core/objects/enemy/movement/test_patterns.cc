//
// Created by rishi on 26-04-2021.
//
#include <catch2/catch.hpp>
#include <ikaruga/core/objects/enemy/movement/patterns.h>

namespace ikaruga::objects::enemy::movement {
TEST_CASE("Enemy movement patterns serialization", "[serialization]") {
  SECTION("Serialization") {
    REQUIRE(nlohmann::json(kInvalid) == "invalid");
    REQUIRE(nlohmann::json(kSineLoop) == "sine-loop");
    REQUIRE(nlohmann::json(kSineLine) == "sine-line");
  }

  SECTION("Deserialization") {
    nlohmann::json json;
    json.push_back("invalid");
    json.push_back(0);
    json.push_back("sine-loop");
    json.push_back("sine-line");
    REQUIRE(json[0].get<movement::Pattern>() == kInvalid);
    REQUIRE(json[1].get<movement::Pattern>() == kInvalid);
    REQUIRE(json[2].get<movement::Pattern>() == kSineLoop);
    REQUIRE(json[3].get<movement::Pattern>() == kSineLine);
  }
}
}