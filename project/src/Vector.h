#ifndef VECTOR_H_
#define VECTOR_H
/**
 * @file vector.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
 /**
 * @brief Class that represents a vector in space.
 * 
 *  
 */
class Vector {
	public:
		double x;
		double y;
		double z;
		/**
		* @brief Constructor.
		*
		* @return Nothing. 
		*/
		Vector(){x = 0.0; y = 0.0; z = 0.0;}
		/**
		* @brief Constructor.
		*
		* @return Nothing. 
		*/
		Vector(double a, double b, double c) {
			x = a;
			y = b;
			z = c;
		}

		/**
		* @brief Equals operator overload.
		*
		* @return Nothing. 
		*/
		void operator = (Vector vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}

		/**
		* @brief Print function.
		*
		* @return Nothing. 
		*/
		void print() {
			printf("%f \t %f \t %f \n", x, y, z);
		}
};
#endif
