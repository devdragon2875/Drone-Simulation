/**
 * @file greyscale_filter.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */


#ifndef GREYSCALE_FILTER_H_
#define GREYSCALE_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for the Greyscale filter. Contains an Apply method which applies a greyscale filter, and the constructor.
 *
 * 
 *  
 */
class GreyScaleFilter : public Filter {
    public:
    /**
      * @brief Default Constructor for the greyscale filter class. 
      * @return Constructs the filter.
      */
    GreyScaleFilter();
    /**
      * @brief Apply function. Applies a greyscale filter to the image in "original" and stores the output in "filtered".
      * @return Nothing. Void function.
      */
    void Apply(vector<Image*> original, vector<Image*> filtered);
};

#endif
