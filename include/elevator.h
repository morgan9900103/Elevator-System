#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator {
public:
  Elevator();
  Elevator(int id, int weight);
  ~Elevator();

  // Mutator
  bool EnterWeight(int weight);

private:
  int id_;
  int weight_;
};

#endif /* ELEVATOR_H */
