//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/objects/player/player.h>
#include "ikaruga/core/objects/player/player_input_component.h"
#include <interface/keyboard.h>
#include <cinder/app/KeyEvent.h>

namespace ikaruga::objects::player {
void PlayerInputComponent::Update(game_engine::GameObject &game_object,
                                  game_engine::GameWorld &game_world) {
  Player *player = dynamic_cast<Player *>(&game_object);
  world::World *world = dynamic_cast<world::World *>(&game_world);
  for (auto const&[key, is_pressed]: interface::Keyboard::GetPressedKeys()) {
    if (is_pressed) {
      switch (key) {
        case ci::app::KeyEvent::KEY_RSHIFT: {
          player->ToggleProjectileType();
          interface::Keyboard::RegisterToggle(ci::app::KeyEvent::KEY_RSHIFT);
          break;
        }
        case ci::app::KeyEvent::KEY_RETURN: {
          if (!player->InCooldown()) {
            world->AddProjectile(player->Shoot(*player));
          }
          break;
        }
        case ci::app::KeyEvent::KEY_LEFT:
          player->TiltAimLeft();
          break;
        case ci::app::KeyEvent::KEY_RIGHT:
          player->TiltAimRight();
          break;
        case ci::app::KeyEvent::KEY_w:
          player->send(1);
          break;
        case ci::app::KeyEvent::KEY_a:
          player->send(2);
          break;
        case ci::app::KeyEvent::KEY_s:
          player->send(3);
          break;
        case ci::app::KeyEvent::KEY_d:
          player->send(4);
          break;
      }
    }
  }
}

void PlayerInputComponent::receive(int message) {

}

}