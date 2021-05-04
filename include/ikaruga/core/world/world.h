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
  virtual ~World();

  void Setup(ikaruga::objects::player::Player *player);
  void Draw() override;
  void Update() override;

  void AddPlayerProjectile(objects::projectile::Projectile *const projectile);
  void AddPlayerProjectile(std::unique_ptr<objects::projectile::Projectile> &&projectile);

  void AddEnemyProjectile(objects::projectile::Projectile *const projectile);
  void AddEnemyProjectile(std::unique_ptr<objects::projectile::Projectile> &&projectile);

  void AddEnemy(std::unique_ptr<ikaruga::objects::enemy::Enemy> &&enemy);

  const std::vector<std::unique_ptr<objects::projectile::Projectile>> &GetPlayerProjectiles() const;
  const std::vector<std::unique_ptr<ikaruga::objects::enemy::Enemy>> &GetEnemies() const;
  objects::player::Player *GetPlayerRef() const;
 private:
  // Holds a reference to a player object for collision functionality
  ikaruga::objects::player::Player *player_ref_;

  // Projectiles shot by the player
  std::vector<std::unique_ptr<objects::projectile::Projectile>>
      player_projectiles_;

  // Projectiles shot by the enemy
  std::vector<std::unique_ptr<objects::projectile::Projectile>>
      enemy_projectiles_;

  // All enemies in the world
  std::vector<std::unique_ptr<ikaruga::objects::enemy::Enemy>> enemies_;

  void UpdateProjectiles();
  void UpdateEnemies();
  void ResolveProjectileEnemyCollisions();
  void ResolvePlayerEnemyCollisions();
};
} // namespace world
} // namespace ikaruga