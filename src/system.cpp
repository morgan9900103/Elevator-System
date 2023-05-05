#include <iostream>

#include "system.h"

// Show the instruction of the simulator
void System::Usage() {
  std::cout << "Welcome to Elevator System Simulator. Please type following commands to interact with the system:" << std::endl;
  std::cout << "\t- add-elevator <elevator-id> <max_weight-supported-in-kgs>" << std::endl;
  std::cout << "\t- status <elevator-id>" << std::endl;
  std::cout << "\t- call-elevator <elevator-id> <floor-name>" << std::endl;
  std::cout << "\t- enter-elevator <elevator-id> <total-weight-in-kgs-entering> <space-seperated-floor-names-requested>" << std::endl;
  std::cout << "\t- exit-elevator <elevator-id> <weight-exiting>" << std::endl;
  std::cout << "\t- continue <elevator-id>" << std::endl;
}

// Add an elevator to the system
bool System::AddElevator(Elevator* elevator) {
  if (ids_.count(elevator->ID()) != 0) {
    return false;
  }
  elevators_.emplace_back(elevator);
  ids_.insert(elevator->ID());
  return true;
}

// main function
void System::Run() {
  Usage();
}
