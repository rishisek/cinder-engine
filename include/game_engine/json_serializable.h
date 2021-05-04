//
// Created by rishi on 25-04-2021.
//
#pragma once
#include <nlohmann/json.hpp>

namespace game_engine {
// Abstract class to hold defined serialization behaviour
class JsonSerializable {
 public:
  virtual void Serialize(nlohmann::json &json) const = 0;
  virtual void Deserialize(const nlohmann::json &json) = 0;
};
}