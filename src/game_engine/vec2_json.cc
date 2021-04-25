//
// Created by rishi on 25-04-2021.
//
#include <game_engine/vec2_json.h>

namespace glm {
void to_json(nlohmann::json &j, const glm::vec2 &vec) {
  j = {{"x", vec.x}, {"y", vec.y}};
};

void from_json(const nlohmann::json &j, glm::vec2 &vec) {
  vec.x = j.at("x").get<float>();
  vec.y = j.at("y").get<float>();
}
}
