//
// Created by rishi on 16-04-2021.
//

#include <interface/keyboard.h>

namespace interface {
std::map<int, bool> Keyboard::keys_;
std::vector<int> Keyboard::toggles_;

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

void Keyboard::RegisterToggle(int key) {
  toggles_.push_back(key);
}

void Keyboard::Release(int key) {
  keys_[key] = false;
}

const std::map<int, bool> &Keyboard::GetPressedKeys() {
  return keys_;
}

void Keyboard::ReleaseAllToggles() {
  for (int key: toggles_) {
    keys_[key] = false;
  }
  toggles_.clear();
}
}