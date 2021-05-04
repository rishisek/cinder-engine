//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/objects/projectile/projectile_shooter.h>
#include <ikaruga/core/objects/projectile/projectile_physics_component.h>

namespace ikaruga::objects::projectile {
void ProjectileShooter::UpdateCooldowns() {
  for (int &cooldown:cooldowns_) {
    cooldown--;
    if (cooldown < 0) {
      cooldown = 0;
    }
  }
}

Projectile *ProjectileShooter::Shoot(game_engine::GameObject const &game_object) {
  cooldowns_[current_projectile_type_index_] =
      projectile_types_[current_projectile_type_index_].GetCooldown();
  game_engine::PhysicsComponent *projectile_physics_component =
      new ProjectilePhysicsComponent(
          physics_component_->GetPosition() + projectile_spawn_offset_,
          glm::vec2(cos(shoot_angle_radians_), sin(shoot_angle_radians_)),
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
                                     const std::vector<ProjectileType> &projectile_types,
                                     const glm::vec2 &projectile_spawn_offset)
    : CharacterObject(physics_component),
      projectile_types_(projectile_types),
      projectile_spawn_offset_(projectile_spawn_offset) {
  cooldowns_.resize(projectile_types_.size());
  for (ProjectileType const &projectile_type:projectile_types_) {
    cooldowns_.push_back(projectile_type.GetCooldown());
  }
}
}