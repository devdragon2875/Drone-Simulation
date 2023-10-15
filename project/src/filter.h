/**
 * @file filter.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

#ifndef FILTER_H_
#define FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "image.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Parent class for the Filters contained in ImageProcessor. Children inherit an Apply function, which applies the filter, and the deconstructor.
 *
 * 
 *  
 */
class Filter {
public:
    /**
      * @brief Virtual Deconstructor for the Filter Class.
      * @return Deconstructs any Filter.
      */
    virtual ~Filter() {};
       /**
      * @brief Virtual apply function. This is the central method of applying a filter. This takes in an array of pointers to images, and changes the images, which is pointed to by the filtered object.
      * @return Applies an arbitrary filter.
      */
    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered)=0;
};
#endif
