//
// Created by rishi on 23-04-2021.
//
#pragma once
#include <nlohmann/json.hpp>
namespace ikaruga::objects::enemy::movement {
enum Pattern {
  kSineLine,
  kSineLoop,
  kCount,
  kInvalid
};

// Macro from the nlohmann-json library defining serialization 
// behavior for Pattern enum
NLOHMANN_JSON_SERIALIZE_ENUM(Pattern, {
  { kInvalid, "invalid" },
  { kSineLine, "sine-line" },
  { kSineLoop, "sine-loop" }
})
} // namespace ikaruga::objects::enemy::movement 