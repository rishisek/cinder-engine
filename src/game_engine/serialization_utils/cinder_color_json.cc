//
// Created by rishi on 25-04-2021.
//
#include <serialization_utils/cinder_color_json.h>

namespace nlohmann {
void adl_serializer<cinder::ColorT<float>>::to_json(json &j,
                                                    const cinder::ColorT<float> &vec) {
  j = nlohmann::json{{"r", vec.r}, {"g", vec.g}, {"b", vec.b}};
}

void adl_serializer<cinder::ColorT<float>>::from_json(const json &j,
                                                      cinder::ColorT<float> &vec) {
  vec.r = j.at("r");
  vec.g = j.at("g");
  vec.b = j.at("b");
}
}

//namespace cinder {
//void to_json(nlohmann::json &j, const ColorT<float> &vec) {
//  j = nlohmann::json{{"r", vec.r}, {"g", vec.g}, {"b", vec.b}};
//}
//
//void from_json(const nlohmann::json &j, ColorT<float> &vec) {
//  vec.r = j.at("r");
//  vec.g = j.at("g");
//  vec.b = j.at("b");
//}
//}
//
//namespace nlohmann {
//cinder::ColorT<float> adl_serializer<cinder::ColorT<float>>::from_json(
//    const json &j) {
//  return {j.at("r"), j.at("g"), j.at("b")};
//}
//
//void adl_serializer<cinder::ColorT<float>>::to_json(json &j,
//                                                    cinder::ColorT<float> t) {
//  j = nlohmann::json{{"r", t.r}, {"g", t.g}, {"b", t.b}};
//}
//}