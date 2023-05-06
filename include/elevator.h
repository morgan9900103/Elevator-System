#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>

class Elevator {
public:
  Elevator();
  Elevator(std::string id, int weight);
  ~Elevator();

  // Mutator
  bool EnterWeight(int weight);

  // Accessor
  std::string ID() const;
  int Weight() const;
  int Floor() const;
private:
  std::string id_;
  int weight_;
  int floor_;
};

#endif /* ELEVATOR_H */
