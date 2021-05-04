//
// Created by rishi on 26-04-2021.
//
#pragma once
#include <vector>
#include <string>

namespace ikaruga::objects::projectile {
class ProjectileType;

class ProjectileFactory {
 public:
  static void AddProjectileType(ProjectileType *projectile_type);
  static std::vector<ProjectileType *> GetTypesById(const std::vector<std::string> &projectile_type_ids);
 private:
  static std::vector<ProjectileType *> projectile_types_;
};
}