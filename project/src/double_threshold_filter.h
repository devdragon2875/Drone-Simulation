/**
 * @file double_threshold_filter.h
 *
 * @copyright 2021 3081W, Group 21, Author: Robert Maple All rights reserved.
 */

#ifndef DoubleThresholdFilter_H_
#define DoubleThresholdFilter_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include <vector>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for the double threshold filter. Apply method applies double threshold filter.
 *
 * 
 *  
 */
class DoubleThresholdFilter : public Filter {
    public:
    /**
      * @brief Default Constructor for DoubleThresholdFilter, takes in two parameters, the higher threshold ratio and the lower threshold ratio.
      * @return Constructs DoubleThresholdFilter.
      */
    DoubleThresholdFilter(float high, float low);
    /**
      * @brief Apply function. Applies a double threshold to the image in "original" and stores the output in "filtered".
      *
      * @return Nothing. Void function.
      */
    void Apply(vector<Image*> original, vector<Image*> filtered);

    private:
    float thresholdRatioHigh,thresholdRatioLow;
};

#endif