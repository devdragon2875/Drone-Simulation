#ifndef PARA_H_
#define PARA_H_

/**
  * @file Para.h
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
 * @brief Class for the Parabolic Movement (Enhancement).  
 */

class Para : public DroneStrategy {
public:
/**
  * @brief General Constructor for Parabolic DroneStrategy
  *
  * @return Nothing. 
  */
  Para();
/**
  * @brief Executes parabolic movement upwards (i.e. over a building) before returning to the original heighth
  *
  * @return Vector of updated direction. 
  */
  Vector Execute(double dt, Point* pos, Vector* dir, double speed);
private:
  double timeElapsed = 0.0;
};

#endif
