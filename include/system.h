#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <set>
#include <string>

#include "elevator.h"

class System {
public:
  bool AddElevator(Elevator* elevator);
private:
  std::vector<Elevator*> elevators_;
  std::set<std::string> ids_;
};  // End System

#endif  /* SYSTEM_H */
