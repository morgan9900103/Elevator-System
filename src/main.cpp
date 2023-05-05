#include <iostream>

#include "elevator.h"
#include "system.h"

int main() {
  Elevator* E1 = new Elevator("E1", 10);
  std::cout << E1->EnterWeight(11) << std::endl;
  
  System system;
  std::cout << system.AddElevator(E1) << std::endl;
  return 0;
}
