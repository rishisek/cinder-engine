//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <vector>
#include <map>

namespace interface {
class Keyboard {
 public:
  static const std::map<int, bool> &GetPressedKeys();
  static bool IsPressed(int key);
  static bool IsReleased(int key);
  static void RegisterToggle(int key);

  static void Press(int key);
  static void Release(int key);
  static void ReleaseAllToggles();
 private:
  static std::map<int, bool> keys_;
  static std::vector<int> toggles_;
};
}