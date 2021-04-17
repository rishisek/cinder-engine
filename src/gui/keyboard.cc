//
// Created by rishi on 16-04-2021.
//

#include <gui/keyboard.h>

namespace gui {
std::map<int, bool> Keyboard::pressed_keys_;

bool Keyboard::IsPressed(int key) {
  return pressed_keys_.at(key);
}

bool Keyboard::IsReleased(int key) {
  return !IsPressed(key);
}

void Keyboard::Press(int key) {
  pressed_keys_[key] = true;
}

void Keyboard::Release(int key) {
  pressed_keys_[key] = false;
}

const std::map<int, bool> &Keyboard::GetPressedKeys() {
  return pressed_keys_;
}
}