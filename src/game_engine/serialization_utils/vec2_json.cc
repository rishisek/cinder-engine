//
// Created by rishi on 25-04-2021.
//
#include <serialization_utils/vec2_json.h>

namespace glm {
void to_json(nlohmann::json &j, const glm::vec2 &vec) {
  j = nlohmann::json{{"x", vec.x}, {"y", vec.y}};
}

void from_json(const nlohmann::json &j, glm::vec2 &vec) {
  vec.x = j.at("x");
  vec.y = j.at("y");
}
}
