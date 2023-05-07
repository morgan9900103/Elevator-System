#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include <deque>

class Elevator {
public:
  Elevator();
  Elevator(std::string id, int weight);
  ~Elevator();

  // Mutator
  bool EnterWeight(int weight);
  void InsertFloor(std::string floor_name);
  void ExtractFloor();
  void ChangeStatus(std::string status);
  void ChangeFloor(std::string floor);

  // Accessor
  std::string ID() const;
  int Weight() const;
  std::string Floor() const;
  std::deque<std::string> FloorDeque() const;
  std::string Status() const;

private:
  std::string id_;
  int weight_;
  std::string floor_;
  std::deque<std::string> floors_deque_;
  std::string status_;
};

#endif /* ELEVATOR_H */
