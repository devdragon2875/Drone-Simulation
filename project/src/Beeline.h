#ifndef BEELINE_H_
#define BEELINE_H_

/**
 * @file Beeline.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "DroneStrategy.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents the strategy of going in a approx straight line twoards a target.
 *
 *
 */

class Beeline : public DroneStrategy {
	public:
		~Beeline(){delete target;}

		Beeline(Point* pos);
		/**
      		* @brief Execute function. This takes in the the current time diff, position, direction, and speed(the current state of the drone) and outputs a Vector representing the direction towards the target point set in the constructor.
      		*
      		* @return A Vector representing the direction towards the target Point.
      		*/
		Vector Execute(double dt, Point* pos, Vector* dir, double speed);
	private:
		Point* target;
};
#endif
