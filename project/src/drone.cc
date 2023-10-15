/**
 * @file drone.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <unistd.h>
#include <cmath>
#include "entity.h"
#include "drone.h"
#include "DroneStrategy.h"
#include "Beeline.h"
#include "Patrol.h"
#include "Para.h"

Drone::Drone(int id, Point* pos, Vector* dir, double speed) {
	this->id = id;
	this->pos = pos;
	this->dir = dir;
	this->speed = speed;
	
	energy = 0;
	returnDir = new Vector();
	returnLoc = new Point();
	returnStrategy = "";
	isCharging = false;
	rechargeLoc = new Point(50, 0, 20);//Location of recharge station
	strategy = "patrol";
	strategies["recharge"] = unique_ptr<DroneStrategy>(new Beeline(new Point(rechargeLoc->x, rechargeLoc->y, rechargeLoc->z)));//Beeline to recharge station 
	strategies["beeline"] = unique_ptr<DroneStrategy>(new Beeline(new Point(40, 0, 40)));//Beeline
	strategies["patrol"] = unique_ptr<DroneStrategy>(new Patrol());//Patrol
	strategies["para"] = unique_ptr<DroneStrategy>(new Para());//Parabolic Movement
}

//Initialize all the drone variables, add getters and setters as needed
Drone::Drone(){
	pos = new Point(0, 10, 0);
	energy = 0;
	returnDir = new Vector();
	returnLoc = new Point();
	returnStrategy = "";
	dir = new Vector();

	isCharging = false;
	rechargeLoc = new Point(50, 0, 20);
	strategy = "patrol";
	strategies["recharge"] = unique_ptr<DroneStrategy>(new Beeline(new Point(rechargeLoc->x, rechargeLoc->y, rechargeLoc->z))); 
	strategies["beeline"] = unique_ptr<DroneStrategy>(new Beeline(new Point(40, 0, 40)));
	strategies["patrol"] = unique_ptr<DroneStrategy>(new Patrol());
	strategies["para"] = unique_ptr<DroneStrategy>(new Para());
	strategies["hospital"] = unique_ptr<DroneStrategy>(new Beeline(new Point(40,40,40)));

}

//setter for strategy
void Drone::ChangeStrategy(std::string s){
	strategy = s;
}

//update
void Drone::Update(double dt) {
	if(energy > 0) { //Checks if we have charge to move
		int distanceRecharge = distanceFrom(rechargeLoc, speed); //Finds the distance to the recharge station
		if(strategy != "recharge" && (int)(energy) <= distanceRecharge){ //Go to the recharge station if we have barely enough energy to make it
			std::cout << "NEED RECHARGE\n";
			returnStrategy = strategy;//Sets the returnStrategy to the current strategy(so we can return to it)
			strategy = "recharge";//Sets the new strategy to recharge
			returnLoc->x = pos->x;//Sets the returnLoc to curr pos(so that we can return to it)
			returnLoc->y = pos->y;
			returnLoc->z = pos->z;
			strategies["return"] = unique_ptr<DroneStrategy>(new Beeline(new Point(returnLoc->x, returnLoc->y, returnLoc->z))); //Beeline startegy to return to original pos
			returnDir->x = dir->x;//Sets the return direction so that we know where to face when returning
			returnDir->y = dir->y;
			returnDir->z = dir->z;
		} else if (strategy == "recharge" && distanceRecharge < 1){ //Checks if we are within a radius of 1 within the recharge station
			std::cout << "RECHARGING: " << energy <<" / " << energyCapacity << "\n";
			isCharging = true;//We then charge if we are in range
			if(energy >= energyCapacity){ //When we reach full charge we...
				std::cout << "FINISHED RECHARGE\n";
				energy = energyCapacity;
				strategy = "return";//...set strategy to return
				isCharging = false;//State we arent charging anymore
			} else {
				energy+=dt; //Charge the drone based on the time passed
			}
		} else if (strategy == "return" && (fabs(pos->x - returnLoc->x) < 0.03)
			      	&& (fabs(pos->y - returnLoc->y) < 0.03)
		      		&& (fabs(pos->z - returnLoc->z) < 0.03)){ // If we get approx within the original position
			cout <<"POSITION " << pos->x << " " << pos->y << " " << pos->z <<"\n";
			cout <<"RETURN LOC " << returnLoc->x << " " << returnLoc->y << " " << returnLoc->z <<"\n";
			
			dir->x = returnDir->x;//Set the direction to the original direction
			dir->y = returnDir->y;
			dir->z = returnDir->z;
			std::cout << "RETURNED \n";
			strategy = returnStrategy;//Set the strategy to the original strategy
			cout << "STRATEGY: " << strategy << "\n";
		}
		if(!isCharging){ //We dont want the drone to deplete energy/move when charging
			Vector output = strategies[strategy]->Execute(dt, pos, dir, speed); // Execute the strategy and get a vector direction on where the drone should move
			speed = 6;//set the speed
			SetJoystick(output.x, output.y, output.z, speed);//change the direction outputted by the execute to the drone
			pos->x += speed*dir->x*dt;//Set the position to a new position based on direcion and speed
			pos->y += speed*dir->y*dt;
			pos->z += speed*dir->z*dt;
    		// Take a picture every 5 seconds with front camera
   	 		time += dt;
			if (time-lastPictureTime > 1.0) {
				std::cout << "ENERGY: " << energy << "\n";//Print statement her so it doesnt spam the command line
				cameras[0]->TakePicture();
				lastPictureTime = time;
			}
			energy -= dt;//Depletes the energy of drone by dt
		}
	} 
	else {
		energy = 0; // If we dont have any energy(set to zero just in case it goes below)
	} 

}

int Drone::distanceFrom(Point* p, double speed){ //Finds the distance to a certain point
	double xDiff = pos->x - p->x;
	double yDiff = pos->y - p->y;
	double zDiff = pos->z - p->z;
	double sum = xDiff*xDiff + yDiff*yDiff + zDiff*zDiff;
	double distance = sqrt(sum)/speed;
	return (int)distance;
}

void Drone::robotFound(Point* p){
	strategy="robotFound";
	strategies["robotFound"] = unique_ptr<DroneStrategy>(new Beeline(new Point(p->x, p->y, p->z)));
	delete p;
}

void Drone::SetJoystick(double x, double y, double z, double a) {
        dir->x = x; dir->y = y; dir->z = z; speed = a;
}
