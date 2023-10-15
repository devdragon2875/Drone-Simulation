#ifndef POINT_H_
#define POINT_H

/**
 * @file point.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
 /*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class that represents a point in space.
 * 
 *  
 */
class Point {
        public:
                double x;
                double y;
                double z;
                /**
                * @brief Constructor.
                *
                * @return Nothing. 
                */
		Point(){x = 0; y = 0; z = 0;}
                /**
                * @brief Constructor.
                *
                * @return Nothing. 
                */
		Point(double a, double b, double c){x = a; y=b; z=c;}
};
#endif

