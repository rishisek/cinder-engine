//
// Created by rishi on 16-04-2021.
//

#include <gui/keyboard.h>

namespace gui {
std::map<int, bool> Keyboard::keys_;

bool Keyboard::IsPressed(int key) {
  if (keys_.count(key) == 0) {
    return false;
  }
  return keys_.at(key);
}

bool Keyboard::IsReleased(int key) {
  if (keys_.count(key) == 0) {
    return false;
  }
  return !IsPressed(key);
}

void Keyboard::Press(int key) {
  keys_[key] = true;
}

void Keyboard::Release(int key) {
  keys_[key] = false;
}

const std::map<int, bool> &Keyboard::GetPressedKeys() {
  return keys_;
}
}