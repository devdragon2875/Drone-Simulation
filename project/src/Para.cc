/**
  * @file Para.cc
  *
  * @copyright 2021 3081W, Group 21 All rights reserved. Author: Kaitlin Pierce
  */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Para.h"
#include <cmath>

Para::Para() {
  //Do nothing
}

Vector Para::Execute(double dt, Point* pos, Vector* dir, double speed) {
  //we are modelling the equation -(1/10)x^2 + pos->y
  timeElapsed += dt;
  
  printf("current Loc : %f %f %f\n", pos->x, pos->y, pos->z);
  printf("timeElapsed: %f\n", timeElapsed);
  
  if(timeElapsed <= 2.5)
  {
  	return Vector(1, pow(timeElapsed, 2), 0);
  }
  else if((timeElapsed > 2.5 && timeElapsed <= 5) && (pos->y >= 2.5)) {
  	return Vector(1, -pow(timeElapsed, 2), 0);
  }
  
  Vector stay;
  return stay;
  
}
