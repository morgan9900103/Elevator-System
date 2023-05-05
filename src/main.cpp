#include <iostream>

#include "elevator.h"

int main() {
  Elevator E1(1, 10);
  std::cout << E1.EnterWeight(11) << std::endl;

  return 0;
}
