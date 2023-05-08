#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include <deque>

class Elevator {
public:
  Elevator();
  Elevator(std::string id, float max_weight);
  ~Elevator();

  // Mutator
  bool EnterWeight(float weight);
  bool ExitWeight(float weight);
  void InsertFloor(std::string floor_name);
  void ExtractFloor();
  void ChangeStatus(std::string status);
  void ChangeFloor(std::string floor);

  // Accessor
  std::string ID() const;
  float MaxWeight() const;
  float CurrentWeight() const;
  std::string Floor() const;
  std::deque<std::string> FloorDeque() const;
  std::string Status() const;

private:
  std::string id_;
  float max_weight_;
  float current_weight_;
  std::string floor_;
  std::deque<std::string> floors_deque_;
  std::string status_;
};

#endif /* ELEVATOR_H */
