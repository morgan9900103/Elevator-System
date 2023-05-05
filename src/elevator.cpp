#include "elevator.h"

Elevator::Elevator() : id_("None"), weight_(0) {}

Elevator::Elevator(std::string id, int weight) : id_(id), weight_(weight) {}

Elevator::~Elevator() {}

bool Elevator::EnterWeight(int weight) {
  if (weight > weight_) {
    return false;
  }

  weight_ -= weight;
  return true;
}

std::string Elevator::ID() const {
  return id_;
}
