#include "system.h"

void System::AddElevator(Elevator* elevator) {
  elevators_.emplace_back(elevator);
}
