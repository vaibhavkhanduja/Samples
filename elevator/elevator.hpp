#include <tuple>
#include <queue>
#include <deque>
#include <vector>


enum DIRECTION  { HALLWAY = 0, DOWN = -1, UP = 1 };
//The structure to describe an elevator and
//its properties.
struct elevator {
  //The unique id of the elevator.
  unsigned int id_;

  //The current floor, where elevator is present.
  unsigned int currentFloorNumber_;

  //The queue of next floors to visit.
  std::queue<int> goalFloorNumber_;

  //Constructor to initialize the elevator.
  elevator(unsigned int _id,
           unsigned int _currentFloorNumber) : 
           id_(_id), currentFloorNumber_(_currentFloorNumber)
	   {
  }

  //Move the elevator to next floor.
  int getNextFloor(int _direction)
  {
     if ((_direction < 0) &&
       (currentFloorNumber_ != 0)) {
       return currentFloorNumber_ - 1;
    } else {
       return currentFloorNumber_ + 1;
    }
    return currentFloorNumber_;
  }
};

//The main class representing the elevator system.
class elevatorSystem {
private:
  //List of elevators.
  std::vector<elevator> elevators_;

  //The tuple with pickup request.
  std::queue<std::tuple<unsigned int, int>> pickUpRequest_;

  //Queue of elevators going UP. To save space, we just use
  //index to the vector elevators.
  std::deque<unsigned int> elevatorsUP_;

  //Queue of elevators going DOWN. To save space, we just use
  //index to the vector elevators.
  std::deque<unsigned int> elevatorsDOWN_;

  //Queue of elevators at HALLWAY or stationary. To save space, we just use
  //index to the vector elevators.
  std::queue<unsigned int> elevatorsHALLWAY_;

  //The main brain method to find the best elevator.
  unsigned int getBestElevator(int direction_, int floor_);

public:
  //Construct elevator system.
  elevatorSystem(int _numberOfElevators);

  //Destroy elevator system.
  virtual ~elevatorSystem();

  //Query the state of elevators returning list of elevators.
  //Each element of the list represening the state: 
  //ElevatorID, Floor Number, Direction.
  std::vector<elevator>& status();

  //Update the status of the elevator, next floor, desired floor and moving it that 
  //floor.
  void update(unsigned int _id, unsigned int _currentFloorNumber,
      unsigned int _goalFloorNumber);

  //Request made by individual, from a floor - the pickup.
  void pickup(unsigned int _floor, int _direction);

  //Simulate the elevator, picking them based on pickup request.
  void step(); 
};
