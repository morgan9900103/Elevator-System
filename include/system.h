#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>

#include "elevator.h"

class System {
public:
  void AddElevator(Elevator* elevator);
private:
  std::vector<Elevator*> elevators_;
};  // End System

#endif  /* SYSTEM_H */
