//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/game_world.h>
#include <ikaruga/core/objects/projectile/projectile.h>
#include <ikaruga/core/objects/enemy/enemy.h>

namespace ikaruga {
namespace objects::player {
class Player;
} // namespace objects::player
namespace world {
class World : public game_engine::GameWorld {
 public:
  World();
  const std::vector<std::unique_ptr<objects::projectile::Projectile>> &GetProjectiles() const;
  const std::vector<std::unique_ptr<ikaruga::objects::enemy::Enemy>> &GetEnemies() const;
  void Setup(ikaruga::objects::player::Player *player);
  void Update() override;
  void AddProjectile(objects::projectile::Projectile *const projectile);
  void AddProjectile(std::unique_ptr<objects::projectile::Projectile> &&projectile);
  void AddEnemy(std::unique_ptr<ikaruga::objects::enemy::Enemy> &&enemy);
  virtual ~World();
 private:
  ikaruga::objects::player::Player *player_ref_;
  std::vector<std::unique_ptr<objects::projectile::Projectile>> projectiles_;
  std::vector<std::unique_ptr<ikaruga::objects::enemy::Enemy>> enemies_;

  void UpdateProjectiles();
  void UpdateEnemies();
  void ResolveProjectileEnemyCollisions();
};
} // namespace world
} // namespace ikaruga