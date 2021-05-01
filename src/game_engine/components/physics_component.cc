//
// Created by rishi on 16-04-2021.
//

#include <game_engine/components/physics_component.h>
#include <serialization_utils/vec2_json.h>

namespace game_engine {
void PhysicsComponent::UpdatePosition() {
  position_ += velocity_;
}

bool PhysicsComponent::Collides(PhysicsComponent *const other) const {
  return collider_mesh_.IsCollision(other->collider_mesh_);
}

const glm::vec2 &PhysicsComponent::GetPosition() const {
  return position_;
}

void PhysicsComponent::SetPosition(const glm::vec2 &position) {
  position_ = position;
}

const glm::vec2 &PhysicsComponent::GetVelocity() const {
  return velocity_;
}

void PhysicsComponent::SetVelocity(const glm::vec2 &velocity) {
  velocity_ = velocity;
}

PhysicsComponent::PhysicsComponent(const glm::vec2 &position,
                                   const glm::vec2 &velocity,
                                   ColliderMesh &&collider_mesh)
    : position_(position),
      velocity_(velocity),
      collider_mesh_(std::move(collider_mesh)) {}

PhysicsComponent::PhysicsComponent(const glm::vec2 &position,
                                   const glm::vec2 &velocity)
    : position_(position), velocity_(velocity) {}

PhysicsComponent::~PhysicsComponent() {

}

void PhysicsComponent::Update() {
  UpdatePosition();
  UpdateColliderMesh();
}

void PhysicsComponent::AddCollider(Collider *collider) {
  collider_mesh_.AddCollider(collider);
}

void PhysicsComponent::UpdateColliderMesh() {
  for (auto collider:collider_mesh_.GetColliders()) {
    collider->UpdatePosition(velocity_);
  }
}

void PhysicsComponent::Serialize(nlohmann::json &json) const {
  json["collider_mesh"] = collider_mesh_;
  json["position"] = position_;
  json["velocity"] = velocity_;
}

void PhysicsComponent::Deserialize(const nlohmann::json &json) {
  collider_mesh_.Deserialize(json);
  position_ = json["position"];
  velocity_ = json["velocity"];
}

const ColliderMesh &PhysicsComponent::GetColliderMesh() const {
  return collider_mesh_;
}

void to_json(nlohmann::json &json, const PhysicsComponent &component) {
  component.Serialize(json);
}

void from_json(const nlohmann::json &json, PhysicsComponent &component) {
  component.Deserialize(json);
}
}