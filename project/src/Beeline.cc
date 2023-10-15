/**
 * @file Beeline.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "Beeline.h"
#include <cmath>
#include <iostream>

Beeline::Beeline(Point* pos){
	target = new Point();
	target->x = pos->x;
	target->y = pos->y;
	target->z = pos->z;
}

Vector Beeline::Execute(double dt, Point* pos, Vector* dir, double speed){
	double val1 = target->x - pos->x;//Find difference
	double val2 = target->y - pos->y;
	double val3 = target->z - pos->z;

	double normVal1 = 0;
	double normVal2 = 0;
	double normVal3 = 0;
	if(fabs(val1) >  0.000002) { //If difference is within threshold to avoid rounding error
		normVal1 = val1/fabs(val1);
	}
	if(fabs(val2) > 0.000002) {
  		normVal2 = val2/fabs(val2);
  	}
	if(fabs(val3) > 0.000002) {
  		normVal3 = val3/fabs(val3);
  	}

	Vector output(normVal1, normVal2, normVal3); 
	return output;
	
}
