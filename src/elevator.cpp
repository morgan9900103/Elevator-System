#include "elevator.h"

Elevator::Elevator() : id_("None"), weight_(0), floor_("0") {}

Elevator::Elevator(std::string id, int weight) : id_(id), weight_(weight), floor_("0") {}

Elevator::~Elevator() {}

bool Elevator::EnterWeight(int weight) {
  if (weight > weight_) {
    return false;
  }

  weight_ -= weight;
  return true;
}

void Elevator::InsertFloor(std::string floor_name) {
  floors_deque_.push_back(floor_name);
}

std::string Elevator::ID() const {
  return id_;
}

int  Elevator::Weight() const {
  return weight_;
}

std::string Elevator::Floor() const {
  return floor_;
}

std::deque<std::string> Elevator::FloorDeque() const {
  return floors_deque_;
}
