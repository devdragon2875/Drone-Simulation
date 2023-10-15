#ifndef PATROL_H_
#define PATROL_H_

/**
  * @file Patrol.h
  *
  * @copyright 2021 3081W, Group 21 All rights reserved. Author: Kaitlin Pierce
  */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "DroneStrategy.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
 * @brief Class for the Patrol Movement (Core).  
 */

class Patrol : public DroneStrategy {
public:
/**
  * @brief General Constructor for Patrol DroneStrategy
  *
  * @return Nothing. 
  */
  Patrol();
/**
  * @brief Executes patrol movement in an outward spiral from initial location
  *
  * @return Vector of updated direction. 
  */
  Vector Execute(double dt, Point* pos, Vector* dir, double speed);
private:
  double timePassed = 1.0;
  int patrolSec = 1;
  int side = -1;
};

#endif
