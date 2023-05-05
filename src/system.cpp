#include "system.h"

bool System::AddElevator(Elevator* elevator) {
  if (ids_.count(elevator->ID()) != 0) {
    return false;
  }
  elevators_.emplace_back(elevator);
  ids_.insert(elevator->ID());
  return true;
}
