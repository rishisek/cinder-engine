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

NLOHMANN_JSON_SERIALIZE_ENUM(Pattern, {
  { kInvalid, "invalid" },
  { kSineLine, "sine-line" },
  { kSineLoop, "sine-loop" }
})
}