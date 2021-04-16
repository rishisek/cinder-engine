//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <vector>

namespace gui {
class Keyboard {
 public:
  static const std::vector<int> &GetPressedKeys();
  static void AddPressedKey(int key);
  static void ClearPressedKeys();
 private:
  static std::vector<int> pressed_keys_;
};
}