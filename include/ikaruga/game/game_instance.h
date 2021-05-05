//
// Created by rishi on 23-04-2021.
//
#pragma once

#include <ikaruga/core/objects/player/player.h>
#include <ikaruga/core/world/world.h>
#include <ikaruga/core/objects/enemy/enemy.h>

namespace ikaruga::game {
class GameInstance {
 public:
  GameInstance();
  virtual ~GameInstance();

  void Setup();
  void Draw();
  void Update();

  double GetWidth() const;
  double GetHeight() const;
  objects::player::Player *GetPlayer() const;
  bool IsPlayerLoss() const;
  bool IsPlayerWin() const;
  bool IsEnded() const;
 private:
  double width_ = 600;
  double height_ = 800;
  ikaruga::objects::player::Player *player_;
  ikaruga::world::World world_;

  bool player_win_ = false;
  bool player_loss_ = false;
  bool ended_ = false;

  void SetupPlayer();
  void SetupEnemies();
};
}
