//
// Created by rishi on 25-04-2021.
//
#pragma once
#include <nlohmann/json.hpp>
#include <glm/vec2.hpp>

// Defines serialization behaviour for glm::vec2
namespace glm {
void to_json(nlohmann::json &j, const glm::vec2 &vec);
void from_json(const nlohmann::json &j, glm::vec2 &vec);
}
