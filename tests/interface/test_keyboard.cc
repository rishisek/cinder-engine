//
// Created by rishi on 18-04-2021.
//

#include <catch2/catch.hpp>
#include <interface/keyboard.h>

namespace interface {
TEST_CASE("Keyboard", "[interface][keyboard]") {
  SECTION("Key press") {
    Keyboard::Press(1);
    REQUIRE(Keyboard::IsPressed(1));
  }

  SECTION("Key release") {
    Keyboard::Release(1);
    REQUIRE(Keyboard::IsReleased(1));
  }
}
}