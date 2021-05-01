//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/objects/projectile/projectile_shooter.h>
#include <ikaruga/core/objects/projectile/projectile_physics_component.h>

namespace ikaruga::objects::projectile {
void ProjectileShooter::UpdateCooldowns() {
  for (ProjectileType &projectile_type: projectile_types_) {
    projectile_type.DecrementCurrentCooldown();
  }
}

Projectile *ProjectileShooter::Shoot(game_engine::GameObject const &game_object) {
  projectile_types_[current_projectile_type_index_].StartCooldown();
  game_engine::PhysicsComponent
      *projectile_physics_component =
      new ProjectilePhysicsComponent(physics_component_->GetPosition(),
                                     glm::vec2(cos(shoot_angle_radians_),
                                               sin(shoot_angle_radians_)),
                                     projectile_types_[current_projectile_type_index_].GetRadius());
  Projectile *projectile =
      new Projectile(projectile_types_[current_projectile_type_index_],
                     projectile_physics_component);
  return projectile;
}

void ProjectileShooter::ToggleProjectileType() {
  current_projectile_type_index_++;
  current_projectile_type_index_ %= projectile_types_.size();
}

ProjectileShooter::ProjectileShooter(game_engine::PhysicsComponent *physics_component,
                                     const std::vector<ProjectileType> &projectile_types)
    : CharacterObject(physics_component), projectile_types_(projectile_types) {}
}