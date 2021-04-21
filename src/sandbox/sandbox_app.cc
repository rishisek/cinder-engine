//
// Created by rishi on 15-04-2021.
//

#include <sandbox/sandbox_app.h>
#include <ikaruga/core/objects/player/player_physics_component.h>
#include <ikaruga/core/objects/player/player_input_component.h>
#include <interface/keyboard.h>
#include <ikaruga/core/world/world_physics_component.h>

namespace sandbox {

Sandbox::Sandbox()
    : player_(
    new PlayerPhysicsComponent(glm::vec2(300, 300), glm::vec2(0, 0)),
    new PlayerInputComponent(),
    std::vector<ProjectileType>{
        ProjectileType(5, ci::Color(0, 1, 0), 50),
        ProjectileType(5, ci::Color(1, 0, 0), 25)
    }), world_(new ikaruga::world::WorldPhysicsComponent()) {}

void Sandbox::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  ci::gl::color(0, 0, 1);
  ci::gl::drawSolidCircle(player_.GetPhysicsComponent()->GetPosition(), 10);
  for (const ikaruga::objects::projectile::Projectile
        *projectile: world_.GetProjectiles()) {
    ci::gl::color(projectile->GetType().GetColor());
    ci::gl::drawSolidCircle(projectile->GetPhysicsComponent()->GetPosition(),
                            projectile->GetType().GetRadius());
  }
}

void Sandbox::mouseDown(ci::app::MouseEvent event) {
}

void Sandbox::mouseDrag(ci::app::MouseEvent event) {
}

void Sandbox::keyDown(ci::app::KeyEvent event) {
  interface::Keyboard::Press(event.getCode());
}

void Sandbox::keyUp(ci::app::KeyEvent event) {
  interface::Keyboard::Release(event.getCode());
}

void Sandbox::setup() {
  player_.GetPhysicsComponent()->SetPosition(glm::vec2(300, 300));
}

void Sandbox::update() {
  player_.Update(world_);
  world_.Update();
  interface::Keyboard::ReleaseAllToggles();
}
}