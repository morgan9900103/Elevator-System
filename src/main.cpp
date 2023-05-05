#include <iostream>

#include "elevator.h"
#include "system.h"

int main() {
  Elevator* E1 = new Elevator(1, 10);
  std::cout << E1->EnterWeight(11) << std::endl;
  
  System system;
  system.AddElevator(E1);
  return 0;
}
