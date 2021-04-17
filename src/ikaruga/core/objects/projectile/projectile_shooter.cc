//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/objects/projectile/projectile_physics_component.h>
#include "ikaruga/core/objects/projectile/projectile_shooter.h"
#include "game_engine/components/physics_component.h"

namespace ikaruga {
void ProjectileShooter::UpdateCooldowns() {
  for (ProjectileType &projectile_type: projectile_types_) {
    projectile_type.DecrementCurrentCooldown();
  }
}

Projectile ProjectileShooter::Shoot(game_engine::GameObject const &game_object) {
  projectile_types_[current_projectile_type_index_].StartCooldown();
  game_engine::PhysicsComponent
      *projectile_physics_component = new ProjectilePhysicsComponent();
  projectile_physics_component->SetPosition(game_object.GetPhysicsComponent()->GetPosition());
  projectile_physics_component->SetVelocity(glm::vec2(cos(shoot_angle_radians_),
                                                      sin(shoot_angle_radians_)));
  return Projectile(projectile_types_[current_projectile_type_index_],
                    projectile_physics_component);
}

void ProjectileShooter::ToggleProjectileType() {
  current_projectile_type_index_++;
  current_projectile_type_index_ %= projectile_types_.size();
}

ProjectileShooter::ProjectileShooter(const std::vector<ProjectileType> &projectile_types)
    : projectile_types_(projectile_types) {}
}