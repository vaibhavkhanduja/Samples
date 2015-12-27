#include "elevator.hpp"
#include <iostream>


//Construct elevator system.
elevatorSystem::elevatorSystem(int _numberOfElevators)
{
  for (int i = 0;i < _numberOfElevators;i++) {
    elevators_.push_back(elevator(i, 0));
    elevatorsHALLWAY_.push(i);
  }
}

//Destroy elevator system.
elevatorSystem::~elevatorSystem()
{
}

//Look for comments in header.
std::vector<elevator>& elevatorSystem::status() 
{
    return elevators_;
}

//Look for comments in header.
void elevatorSystem::update(unsigned int _id, unsigned int _currentFloorNumber,
      unsigned int _goalFloorNumber) {
     elevators_[_id].currentFloorNumber_ = _currentFloorNumber;
     elevators_[_id].goalFloorNumber_.push(_goalFloorNumber);
}

//Look for comments in header.
void elevatorSystem::pickup(unsigned int _floor, int _direction)
{
    pickUpRequest_.push(std::make_tuple(_floor, _direction));
}

//Pick the best elevator based on following logic:
//STEP 1: Look for elevator going in the same direction.
//STEP 1a: If elevator found in the same direction, check for the last goal floor, else go to STEP 2.
//STEP 1b: If last goal floor is more for UP request and LESS for DOWN, choose the elevator, else go to STEP 2.
//STEP 2: Look for elevator present in the HALLWAY. If not found got to STEP 3.
//STEP 2a: Elevator found in HALLWAY, pop from HALLWAY queue and put it in the DIRECTION queue.
//STEP 3: No elevator found in HALLWAY queue, get elevator from DOWN queue i.e. any elevator going down. Put the elevator 
         //in the DIRECTION QUEUE.
unsigned int elevatorSystem::getBestElevator(int _direction, int _floor)
{
  unsigned int elevatorIndex = 0;
  if ((_direction < 0) && elevatorsDOWN_.size() > 0) {
      for (int i=0;i<elevatorsDOWN_.size();i++) {
       //TODO something can be done to improve this traversal.
        if (elevators_[elevatorsDOWN_[i]].goalFloorNumber_.back() > _floor) {
           return elevatorsDOWN_[i];
        }
      }
  }
 
  if ((_direction > 0) && (elevatorsUP_.size() > 0)) {
      for (int i=0;i<elevatorsUP_.size();i++) {
       //TODO something can be done to improve this traversal.
        if (elevators_[elevatorsUP_[i]].goalFloorNumber_.back() < _floor) {
           return elevatorsUP_[i];
        }
      }
  }

  //This code gets called if no elevator going in a desired
  //direction is NOT found.
  if (elevatorsHALLWAY_.size() > 0) {
    elevatorIndex = elevatorsHALLWAY_.front();
    elevatorsHALLWAY_.pop();
  }
  //No elevator stationary or at HALLWAY.
  else if (elevatorsDOWN_.size() > 0) {
    elevatorIndex = elevatorsDOWN_.front();
  }
  if (_direction > 0) {
    elevatorsUP_.push_back(elevatorIndex);
  }
  if (_direction < 0) {
    elevatorsDOWN_.push_back(elevatorIndex);
  }
  //TODO Move elevator from UP and DOWN queue back to HALLWAY queue, if the current floor for them is 
  //HALLWAY or they are stationary.
  return elevatorIndex;
}
//Time Step the elevator system.
void elevatorSystem::step()
{
   //Get the best elevator and service the pick request.
   std::tuple<int, int> pickup = pickUpRequest_.front();

   unsigned int elevatorIndex = getBestElevator(std::get<0>(pickup), std::get<1>(pickup));

   std::cout << "Sending pickup request for " << std::get<1>(pickup) << " for elevator " << elevatorIndex << std::endl;

   update(elevatorIndex, elevators_[elevatorIndex].getNextFloor(std::get<0>(pickup)), std::get<1>(pickup));

   //Delete the pickup request.
   pickUpRequest_.pop();
}

int main(int argc, char** argv)
{
  elevatorSystem l_elevatorSystem(16);
  l_elevatorSystem.pickup(UP, 4);
  l_elevatorSystem.step();
  l_elevatorSystem.pickup(DOWN, 7);
  l_elevatorSystem.step();
  l_elevatorSystem.pickup(UP, 6);
  l_elevatorSystem.step();
  l_elevatorSystem.pickup(UP, 5);
  l_elevatorSystem.step();
  l_elevatorSystem.pickup(DOWN, 2);
  l_elevatorSystem.step();
  return 0;
}
