/**
  * @file Patrol.cc
  *
  * @copyright 2021 3081W, Group 21 All rights reserved. Author: Kaitlin Pierce
  */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Patrol.h"
#include <cmath>

Patrol::Patrol() {
	//Do nothing
}

Vector Patrol::Execute(double dt, Point* pos, Vector* dir, double speed) {
	//The key is to find an appropriate speed and patrolSec increment such that the search
	// is efficient.
	//patrolSec controls the size of the next search square and speed effects the number
	// of photographs taken.
	Vector output;

	timePassed += dt;

	if((int)timePassed == patrolSec) {
		side++; //we have completed a side
		if(side == 2) {
			side = 0;
			patrolSec += 2;
		}
		timePassed = 0.0;
		if((int)dir->z == 0 && (int)dir->x == 0) {
			output.x = 0;
			output.z = 1;
			return output;
		}
		else if((int)dir->z == 1) {
			output.z = 0;
			output.x = -1;
			return output;
		}
		else if((int)dir->x == -1) {
			output.z = -1;
			output.x = 0;
			return output;
		}
		else if((int)dir->z == -1) {
			output.z = 0;
			output.x = 1;
			return output;
		}
		else if((int)dir->x == 1) {
			output.z = 1;
			output.x = 0;
			return output;
		}
	}

	output = *dir;
	return output;

}
