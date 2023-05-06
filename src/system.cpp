#include <iostream>
#include <sstream>

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
  std::cout << "\t- quit" << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

// Add an elevator to the system
void System::AddElevator(std::string id, int weight) {
  // Check id
  if (ids_.count(id) != 0) {
    std::cout << "ID: " << id << " already exist in the system" << std::endl;
    return;
  }

  // Check weight
  if (weight <= 0) {
    std::cout << "Weight must larger than 0" << std::endl;
    return;
  }

  Elevator* elevator = new Elevator(id, weight);
  elevators_.emplace_back(elevator);
  ids_.insert(id);
}

// Acquire specific elevator's status
void System::Status(std::string id) const {
  // Check id
  if (ids_.count(id) == 0) {
    std::cout << "No ID: " << id << " in the system." << std::endl;
    return;
  }
  
  // Search the elevator
  Elevator* elevator = Find(id);
  
  // Print the status
  std::cout << "elevator id: " << elevator->ID()
            << ", remaining weight: " << elevator->Weight()
            << ", current floor: " << elevator->Floor()
            << std::endl;
}

// Search the elevator given id
Elevator* System::Find(std::string id) const {
  for (const auto elevator : elevators_) {
    if (elevator->ID() == id) {
      return elevator;
    }
  }
  
  // Shouldn't reach here
  std::cout << "No ID found. Error" << std::endl;
  return nullptr;
}

// main function
void System::Run() {
  Usage();

  std::string input;
  while (true) {
    std::cout << "\nPlease enter your input:" << std::endl;
    std::getline(std::cin, input);
    std::stringstream inputstream(input);
    std::string command;
    inputstream >> command;
    if (command == "quit") {
      std::cout << "\nExiting the simulator" << std::endl;
      break;
    }
    else {
      // add-elevator <elevator-id> <max_weight-supported-in-kgs>
      if (command == "add-elevator") {
        std::string elevator_id, weight;
        inputstream >> elevator_id >> weight;
        AddElevator(elevator_id, std::stoi(weight));
      }

      // status <elevator-id>
      else if (command == "status") {
        std::string elevator_id;
        inputstream >> elevator_id;
        Status(elevator_id);
      }
    }
  }
}
