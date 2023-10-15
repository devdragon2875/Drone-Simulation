
#ifndef IDLE_H_
#define IDLE_H_
/**
 * @file Idle.h
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
 * @brief Represents the strategy fo keeping the drone idle.
 *
 *
 */


class Idle: public DroneStrategy {
        public:
                ~Idle(){}
                Idle(){}

		 /**
                * @brief A strategy pattern that makes the drone idle. 
                *
                * @return A Vector direction of (0, 0, 0) (idle)
                */

                Vector Execute(double dt, Point* pos, Vector* dir, double speed);
        
};
#endif

