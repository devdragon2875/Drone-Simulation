#ifndef DRONE_STRATEGY_H_
#define DRONE_STRATEGY_H_
/**
 * @file DroneStrategy.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include "Vector.h"
//#include "Point.h"
#include "entity.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This abstract class represents the movement strategy of the drone. Uses the Execute method to represent the strategy.
 *
 *
 */


class DroneStrategy {
	public:
		
		virtual ~DroneStrategy() {};
		
		/**
         	* @brief This is a purely virtual function representing the execution of a strategy. This takes in the state of the drone(time, pos, dir, speed) and gives a resulting vector.
         	*
         	* @return A Vector representing the direction in which the strategy pattern moves.
         	*/

		virtual Vector Execute(double dt, Point* pos, Vector* dir, double speed)= 0 ;
};
#endif
