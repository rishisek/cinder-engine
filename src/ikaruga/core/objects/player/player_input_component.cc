//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/objects/player/player.h>
#include "ikaruga/core/objects/player/player_input_component.h"
#include <gui/keyboard.h>
#include <cinder/app/KeyEvent.h>

namespace ikaruga {
void PlayerInputComponent::Update(game_engine::GameObject &game_object,
                                  ikaruga::World &world) {
  Player* player = dynamic_cast<Player*>(&game_object);
  for (int key: gui::Keyboard::GetPressedKeys()) {
    switch (key) {
      case ci::app::KeyEvent::KEY_RSHIFT:
        player->ToggleProjectileType();
        break;
      case ci::app::KeyEvent::KEY_RETURN: {
        if (!player->InCooldown()) {
          world.AddProjectile(player->Shoot(*player));
        }
        break;
      }
      case ci::app::KeyEvent::KEY_LEFT:
        player->TiltAimLeft();
        break;
      case ci::app::KeyEvent::KEY_RIGHT:
        player->TiltAimRight();
        break;
    }
  }
  gui::Keyboard::ClearPressedKeys();
}
}