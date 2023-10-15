
#ifndef VANTAGE_H_
#define VANTAGE_H_
/**
 * @file Vantage.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
 /*******************************************************************************
 * Class Definitions
 ******************************************************************************/
#include "DroneStrategy.h"
/**
 * @brief Class moves drone to a vantage point vertically.
 * 
 *  
 */
class Vantage: public DroneStrategy {
public:
        /**
        * @brief Destructor.
        *
        * @return Nothing. 
        */
        ~Vantage(){}
        /**
        * @brief Constructor.
        *
        * @return Nothing. 
        */
        Vantage(){}
        /**
        * @brief Execute's the vantage movement.
        *
        * @return Vector describing the movement.
        */
        Vector Execute(double dt, Point* pos, Vector* dir, double speed);

};
#endif

