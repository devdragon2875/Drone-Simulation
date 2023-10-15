/**
 * @file invert.h
 */

#ifndef INVERT_H
#define INVERT_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class that inverts the colors in an image
 */
class Invert : public Filter {

    public:
/**
  * @brief Default constructor
  */
        Invert();
/**
  * @brief Applies the filter to an image input vector "original" 
  */
        void Apply(vector<Image*> original, vector<Image*> filtered);
};

#endif