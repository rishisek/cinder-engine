//
// Created by rishi on 26-04-2021.
//
#include <ikaruga/core/objects/projectile/projectile_factory.h>
#include <ikaruga/core/objects/projectile/projectile_type.h>

namespace ikaruga::objects::projectile {
std::vector<ProjectileType *> ProjectileFactory::projectile_types_;

void ProjectileFactory::AddProjectileType(ProjectileType *projectile_type) {
  projectile_types_.push_back(projectile_type);
}

std::vector<ProjectileType *> ProjectileFactory::GetTypesById(const std::vector<
    std::string> &projectile_type_ids) {
  std::vector<ProjectileType *> list;
  for (std::string const &id: projectile_type_ids) {
    auto it = find_if(projectile_types_.begin(),
                      projectile_types_.end(),
                      [&](const ProjectileType *const &projectile_type) {
                        return projectile_type->GetId() == id;
                      });
    if (it != projectile_types_.end()) {
      list.push_back(*it);
    }
  }
  return list;
}

ProjectileFactory::~ProjectileFactory() {
  for (ProjectileType *projectile_type: projectile_types_) {
    delete projectile_type;
  }
}
}