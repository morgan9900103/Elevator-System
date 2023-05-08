#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
void System::AddElevator(std::string id, float weight) {
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
  std::cout << "\televator id: " << elevator->ID() << std::endl
            << "\tmax weight available: " << elevator->MaxWeight() << std::endl
            << "\tcurrent weight: " << elevator->CurrentWeight() << std::endl
            << "\tcurrent floor: " << elevator->Floor() << std::endl
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

// Call elevator to specific floor
void System::CallElevator(std::string id, std::string floor_name) {
  // Check id
  if (ids_.count(id) == 0) {
    std::cout << "No ID: " << id << " in the system." << std::endl;
    return;
  }

  // Search the elevator
  Elevator* elevator = Find(id);

  elevator->InsertFloor(floor_name);
  std::cout << "Insert " << floor_name << " to " << elevator->ID() << "'s queue. There are ";
  for (size_t i = 0; i < elevator->FloorDeque().size(); i++) {
    std::cout << elevator->FloorDeque().at(i) << ", ";
  }
  std::cout << "in the queue." << std::endl;
}

// Do next action for the elevator
void System::Continue(std::string id) {
  // check id
  if (ids_.count(id) == 0) {
    std::cout << "No ID: " << id << " in the system." << std::endl;
    return;
  }

  // Search the elevator
  Elevator* elevator = Find(id);

  // 1. elevator stationay, no next_floor: Stay stationary
  // 2. elevator stationary, has next_floor: Change to moving
  // 3. elevator moving, about to be at next_floor: Change to stationary
  if (elevator->Status() == "stationary") {
    if (elevator->FloorDeque().size() == 0) {
      std::cout << "Elevator " << elevator->ID() << " is at " << elevator->Floor() << " stationary." << std::endl;
    }
    else if (elevator->FloorDeque().size() > 0) {
      elevator->ChangeStatus("moving");
      std::cout << "Elevator " << elevator->ID() << " is moving from " << elevator->Floor() << " to " << elevator->FloorDeque().front() << std::endl;
    }
  }
  else if (elevator->Status() == "moving") {
    elevator->ChangeStatus("stationary");
    elevator->ChangeFloor(elevator->FloorDeque().front());
    elevator->ExtractFloor();
    std::cout << "Elevator " << elevator->ID() << " is at " << elevator->Floor() << " stationary." << std::endl;
  }
}

// Support for people getting in the elevators and requesting floor
void System::EnterElevator(std::string id, float weight, std::vector<std::string> floors) {
  // check weight is valid
  if (weight < 0) {
    std::cout << "Weight must greater than or equal to 0" << std::endl;
    return;
  }

  // check id
  if (ids_.count(id) == 0) {
    std::cout << "No ID: " << id << " in the system." << std::endl;
    return;
  }

  // Search the elevator
  Elevator* elevator = Find(id);

  // Enter weight to the elevator
  if (elevator->EnterWeight(weight)) {
    std::cout << "Entering " << weight << " kg to the elevator " << elevator->ID() << ". Current weight in the elevator: " << elevator->CurrentWeight() << std::endl;
  }
  // Should not reach here
  else {
    std::cout << "Failed to enter " << weight << " kg to the elevator " << elevator->ID() << std::endl;
    return;
  }

  // Add floor to deque
  for (const auto& floor : floors) {
    elevator->InsertFloor(floor);
    std::cout << "Insert " << floor << " to " << elevator->ID() << "'s queue." << std::endl;
  }
  std::cout << "There are ";
  for (size_t i = 0; i < elevator->FloorDeque().size(); i++) {
    std::cout << elevator->FloorDeque().at(i) << ", ";
  }
  std::cout << "in the queue." << std::endl;
}

// Support for people getting out the elevators
void System::ExitElevator(std::string id, float weight) {
  // check weight is valid
  if (weight < 0) {
    std::cout << "Weight must greater than or equal to 0" << std::endl;
    return;
  }

  // check id
  if (ids_.count(id) == 0) {
    std::cout << "No ID: " << id << " in the system." << std::endl;
    return;
  }

  // Search the elevator
  Elevator* elevator = Find(id);

  // Only when elevator is stationary can people exit elevator
  if (elevator->Status() != "stationary" ) {
    std::cout << "Can't exit when elevator is moving." << std::endl;
    return;
  }

  // Exit weight from the elevator
  if (elevator->ExitWeight(weight)) {
    std::cout << "Exiting " << weight << " kg from elevator " << elevator->ID() << ". Current weight in the elevator: " << elevator->CurrentWeight() << std::endl;
  }

  // Should not reach here
  else {
    std::cout << "Failed to exiting " << weight << " kg from elevator " << elevator->ID() << std::endl;
  }
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
        AddElevator(elevator_id, std::stof(weight));
      }

      // status <elevator-id>
      else if (command == "status") {
        std::string elevator_id;
        inputstream >> elevator_id;
        Status(elevator_id);
      }

      // call-elevator <elevator-id> <floor-name>
      else if (command == "call-elevator") {
        std::string elevator_id, floor_name;
        inputstream >> elevator_id >> floor_name;
        CallElevator(elevator_id, floor_name);
      }

      // continue <elevator-id>
      else if (command == "continue") {
        std::string elevator_id;
        inputstream >> elevator_id;
        Continue(elevator_id);
      }

      // enter-elevator <elevator-id> <entering-weight> [optional]<floor-name-1> [optional]<floor-name-12> ...
      else if (command == "enter-elevator") {
        std::string elevator_id, weight, floor;
        std::vector<std::string> floors;
        inputstream >> elevator_id >> weight;
        while (inputstream >> floor) {
          floors.emplace_back(floor);
        }

        EnterElevator(elevator_id, std::stof(weight), floors);
      }

      // exit-elevator
      else if (command == "exit-elevator") {
        std::string elevator_id, weight;
        inputstream >> elevator_id >> weight;
        ExitElevator(elevator_id, std::stof(weight));
      }
      
      // Invalid command
      else {
        std::cout << "Invalid command" << std::endl;
      }
    }
  }
}
