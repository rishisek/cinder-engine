//
// Created by rishi on 25-04-2021.
//
#pragma once
#include <nlohmann/json.hpp>
#include <cinder/Color.h>
//
// partial specialization (full specialization works too)
namespace nlohmann {
template<>
struct adl_serializer<cinder::ColorT<float>> {
  static void to_json(json &j, const cinder::ColorT<float> &vec);

  static void from_json(const json &j, cinder::ColorT<float> &vec);
};
}
//
//namespace cinder {
//void to_json(nlohmann::json &j, const cinder::ColorT<float> &vec);
//void from_json(const nlohmann::json &j, cinder::ColorT<float> &vec);
//}
//
//namespace nlohmann {
//template<>
//struct adl_serializer<cinder::ColorT<float>> {
//  // note: the return type is no longer 'void', and the method only takes
//  // one argument
//  static cinder::ColorT<float> from_json(const json &j);
//
//  // Here's the catch! You must provide a to_json method! Otherwise you
//  // will not be able to convert cinder::ColorT<float> to json, since you fully
//  // specialized adl_serializer on that type
//  static void to_json(json &j, cinder::ColorT<float> t);
//};
//}