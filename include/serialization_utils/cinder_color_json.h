//
// Created by rishi on 25-04-2021.
//
#pragma once
#include <nlohmann/json.hpp>
#include <cinder/Color.h>

namespace nlohmann {
// Defines serialization behavior for cinder::ColorT<float> and thereby
// other cinder::ColorT templates.
template<>
struct adl_serializer<cinder::ColorT<float>> {
  static void to_json(json &j, const cinder::ColorT<float> &vec);

  static void from_json(const json &j, cinder::ColorT<float> &vec);
};
}