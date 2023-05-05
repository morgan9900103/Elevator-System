#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <set>
#include <string>

#include "elevator.h"

class System {
public:
  void Run();
  
private:
  void Usage();
  bool AddElevator(Elevator* elevator);
  
  std::vector<Elevator*> elevators_;
  std::set<std::string> ids_;
};  // End System

#endif  /* SYSTEM_H */
