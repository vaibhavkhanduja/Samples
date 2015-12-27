##Description
Design and implement an elevator control system. What data structures,
interfaces and algorithms will you need? Your elevator control system should
be able to handle a few elevators -- up to 16.

You can use the language of your choice to implement an elevator control
system. In the end, your control system should provide an interface for:

  * Querying the state of the elevators (what floor are they on and where they
    are going),

  * receiving an update about the status of an elevator,

  * receiving a pickup request,

  * time-stepping the simulation.

For example, we could imagine in Scala an interface like this:

	trait ElevatorControlSystem {
		def status(): Seq[(Int, Int, Int)]
		def update(Int, Int, Int)
		def pickup(Int, Int)
		def step()
	}

Here we have chosen to represent elevator state as 3 integers:

  Elevator ID, Floor Number, Goal Floor Number

An update alters these numbers for one elevator. A pickup request is two
integers:

  Pickup Floor, Direction (negative for down, positive for up)

This is not a particularly nice interface, and leaves some questions open. For
example, the elevator state only has one goal floor; but it is conceivable
that an elevator holds more than one person, and each person wants to go to a
different floor, so there could be a few goal floors queued up.

=========================================

##Solution
A simple solution to the problem can be FCFS ( First come first serve). Elevators work depends on the order of every request. The first one who sends the request can take the elevator first. Thus, making elevator move in all direction, which offcource is not efficient. 

It is important to make sure that elevator always move in the same direction. This shall make sure request for pickup are serviced in least amount of time.
Elevators turn back when they reach the top or the bottom

###Proposed Solution

The solution keeps track of the direction of the elevator. Three seperate queues

 * Elevators in HALLWAY
 * Elevators going UP
 * Elevators going DOWN.
 
To optimize, these queue only contain index of one large elevator vector, instead of elevator object.
	
The main logic lies in the method **getBestElevator**, which pulls elevators from their respective queue and assigns them pickup request. 

The function logic can be decribed as below

1.	Traverse through the elevator queue, picking the queue based on the requested direction. If no elements found in the queue, goto step "3".
2.	From the respective elevator queue (UP or DOWN), traverse and compare the last goal floor of the elevator. If last goal floor, is less then for UP request and more than for DOWN request then pick up the elevator. If none found, the goto STEP "3".
3.	Look for elevators in the HALLWAY queue and assign the elevator. If no elevator found in the HALLWAY queue, go to STEP "5"
4.	Move the elevator from HALLWAY queue to the direction queue. GOTO STEP "6"
5.	Look for elevators in the DOWN queue and assign the elevator.
6.	Return the index vector of the elevator queue as assigned elevator.

###Compile
The code is written in C++ and can be compiled on a Linux environment. A sample vagrant file can be used to create dev & test environment.

1.	vagrant up -> this install all necessary tools in ubuntu vagrant machine.
2.	vagrant ssh
3.	cd /vagrant
4.	make

######Make Clean<br>
1.	cd /vagrant <br>
2.	make clean <br>

###Run:<br>
Few examples with testcases,  which simulate the scenario of requests. The program can be executed by running /vagrant/elevator.

