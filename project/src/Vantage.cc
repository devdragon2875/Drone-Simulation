/**
 * @file Vantage.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Vantage.h"
  
Vector Vantage::Execute(double dt, Point* pos, Vector* dir, double speed){
        Vector output(dir->x, 1, dir->z);
        return output;
}

