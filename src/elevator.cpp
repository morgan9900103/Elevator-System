#include "elevator.h"

Elevator::Elevator() : id_("None"), weight_(0), floor_("0"), status_("stationary") {}

Elevator::Elevator(std::string id, int weight) : id_(id), weight_(weight), floor_("0"), status_("stationary") {}

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

void Elevator::ExtractFloor() {
  floors_deque_.pop_front();
}

void Elevator::ChangeStatus(std::string status) {
  status_ = status;
}

void Elevator::ChangeFloor(std::string floor) {
  floor_ = floor;
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

std::string Elevator::Status() const {
  return status_;
}
