//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/player.h"

namespace ikaruga {
Player::Player(const std::vector<ProjectileType> &projectile_types,
               const glm::vec2 &position,
               const glm::vec2 &velocity) : FlyerCharacter(projectile_types,
                                                           position,
                                                           velocity) {

}
}