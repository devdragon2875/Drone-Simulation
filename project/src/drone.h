#ifndef DRONE_H_
#define DRONE_H_

/**
 * @file drone.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/



#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "camera.h"
#include "imageProcessor.h"
#include "DroneStrategy.h"
#include "entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class that represents the Drone. It has a position and direction and updates them based on a strategy in the Update(dt) function. Extends the Entity class.
 *
 *
 */

class Drone : public Entity {
public:
	/**
         * @brief Default Constructor. Initializes all of the field variables to default.
         *
         * @return Nothing.
         */

	Drone();

	/**
         * @brief Destructor. Deletes the position, direction, recharge station location, saved return location, and saved return direction.
         *
         * @return Nothing.
         */
	
	~Drone(){delete pos; delete dir; delete rechargeLoc; delete returnLoc; delete returnDir;}
	
	/**
         * @brief Initalizes the id, position, direction, and speed of the drone.
         *
         * @return Nothing.
         */
	
	Drone(int id, Point* pos, Vector* dir, double speed);
	
	/**
         * @brief This changes the current strategy to whatever strategy is specified as the parameter. (Strategies such as "patrol", "beeline", "recharge", etc.)
         *
         * @return Nothing.
         */

	void ChangeStrategy(std::string strategy);
	
	/**
         * @brief This Updates the condition of the drone. This means that the drone will execute what strategy it is on(assuming it has charge) and will change its position and directionto reflect that.
         *
         * @return Nothing.
         */
	
	void Update(double dt);
    	
	/**
         * @brief Creates a beeline strategy named "robotfound" and beelines towards the point.
         *
         * @return Nothing.
         */

	void robotFound(Point* p);
        
        
	std::vector<Camera*> cameras;//represents the cameras of the drone

	//Getters and Setters
	void SetJoystick(double x, double y, double z, double a);
	int getID(){return id;}
	void setXDir(double x) {dir->x = x;}
    	void setYDir(double y) {dir->y = y;}
    	void setZDir(double z) {dir->z = z;}
	double getX() {return pos->x;}
	double getY() {return pos->y;}
	double getZ() {return pos->z;}
	double getXDir() {return dir->x;}
	double getYDir() {return dir->y;}
	double getZDir() {return dir->z;}
	double getSpeed() {return speed;}
	Vector* getDir() {return dir;}
	Point* getPos() {return pos;}
	void setID(double val){id=val;}
	void setSpeed(double val){speed=val;}
	bool getIsCharging(){return isCharging;};
	std::string getStrategy() { return strategy; }
private:
	std::string strategy; //Represents the current strategy in string form
	std::map<std::string, unique_ptr<DroneStrategy>> strategies; // A map from the key "strategy" to the DroneStrategy
	Point* rechargeLoc; //Location of the Recharge Station
	bool isCharging; //Represents if the drone is charging
	Point* returnLoc; //The location of where the drone to return to when using "return" strategy
	Vector* returnDir; //The direction the drone was facing for the "return" strategy to return to
	std::string returnStrategy; // The original strategy that the "return" strategy will return to
	Vector* dir; //The direction of the drone
	double speed; //The speed of the drone
	int id; // The id of the drone
	float lastPictureTime = 0.0; // the last time a picture was taken
	float time = 0.0; // the current tracker of time
	int distanceFrom(Point* p, double speed); // A helper function allowing us to find the distance to a certain pt(mainly for "recharge")
};
#endif