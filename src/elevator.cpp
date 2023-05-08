#include <iostream>

#include "elevator.h"

Elevator::Elevator() : id_("None"), max_weight_(0.0), current_weight_(0.0), floor_("0"), status_("stationary") {}

Elevator::Elevator(std::string id, float weight) : id_(id), max_weight_(weight), current_weight_(0.0), floor_("0"), status_("stationary") {}

Elevator::~Elevator() {}

bool Elevator::EnterWeight(float weight) {
  if (weight < 0 || weight + current_weight_ > max_weight_) {
    return false;
  }

  current_weight_ += weight;
  return true;
}

bool Elevator::ExitWeight(float weight) {
  if (weight < 0 || current_weight_ - weight < 0) {
    return false;
  }

  current_weight_ -= weight;
  return true;
}

void Elevator::InsertFloor(std::string floor_name) {
  for (const auto& floor : floors_deque_) {
    if (floor == floor_name) {
      return;
    }
  }
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

float Elevator::MaxWeight() const {
  return max_weight_;
}

float Elevator::CurrentWeight() const {
  return current_weight_;
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
