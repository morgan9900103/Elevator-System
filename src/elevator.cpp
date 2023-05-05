#include "elevator.h"

Elevator::Elevator() : id_(0), weight_(0) {}

Elevator::Elevator(int id, int weight) : id_(id), weight_(weight) {}

Elevator::~Elevator() {}

bool Elevator::EnterWeight(int weight) {
  if (weight > weight_) {
    return false;
  }

  weight_ -= weight;
  return true;
}
