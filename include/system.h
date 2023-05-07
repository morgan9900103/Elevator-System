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
  void AddElevator(std::string id, int weight);
  void Status(std::string id) const;
  Elevator* Find(std::string id) const;
  void CallElevator(std::string id, std::string floor_name);
  void Continue(std::string id);

  std::vector<Elevator*> elevators_;
  std::set<std::string> ids_;
};  // End System

#endif  /* SYSTEM_H */
