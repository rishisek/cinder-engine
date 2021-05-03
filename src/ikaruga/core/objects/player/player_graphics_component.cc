//
// Created by rishi on 01-05-2021.
//

#include <ikaruga/core/objects/player/player_graphics_component.h>
#include <cinder/gl/gl.h>
#include <cinder/app/AppBase.h>

namespace ikaruga::objects::player {
void PlayerGraphicsComponent::Render() const {
  using namespace ci;
  gl::color(1, 1, 1);
  static gl::Texture2dRef sprite =
      gl::Texture2d::create(loadImage(app::loadAsset("player_sprite.png")));
  gl::draw(sprite, position_);
}

void PlayerGraphicsComponent::receive(int message) {

}

PlayerGraphicsComponent::PlayerGraphicsComponent(const glm::vec2 &position)
    : GraphicsComponent(position) {}
}
