//
// Created by rishi on 16-04-2021.
//

#include "game_engine/objects/character_object.h"

namespace game_engine {

CharacterObject::CharacterObject(PhysicsComponent *physics_component)
    : GameObject(physics_component) {}
}