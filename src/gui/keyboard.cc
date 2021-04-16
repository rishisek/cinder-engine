//
// Created by rishi on 16-04-2021.
//

#include <gui/keyboard.h>

namespace gui {
std::vector<int> Keyboard::pressed_keys_;

const std::vector<int> &Keyboard::GetPressedKeys() {
  return pressed_keys_;
}

void Keyboard::AddPressedKey(int key) {
  pressed_keys_.push_back(key);
}

void Keyboard::ClearPressedKeys() {
  pressed_keys_.clear();
}
}