//
// Created by rishi on 01-05-2021.
//

#include <ikaruga/core/objects/enemy/enemy_graphics_component.h>
#include <cinder/gl/gl.h>
#include <cinder/app/AppBase.h>

namespace ikaruga::objects::enemy {
void EnemyGraphicsComponent::Render() const {
  using namespace ci;
  gl::color(color_);
  static gl::Texture2dRef sprite =
      gl::Texture2d::create(loadImage(app::loadAsset("enemy_sprite.png")));
  gl::draw(sprite, glm::vec2());
}

void EnemyGraphicsComponent::receive(int message) {

}

EnemyGraphicsComponent::EnemyGraphicsComponent(const glm::vec2 &position,
                                               const ci::ColorT<float> &enemy_color)
    : GraphicsComponent(position),
      color_(enemy_color) {}
} // namespace ikaruga::objects::enemy 