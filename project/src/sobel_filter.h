/**
 * @file sobel_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */
#ifndef SOBELFILTER_H_
#define SOBELFILTER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include <vector>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
 * @brief Sobel Filter object applies the sobel filter to a provided image and returns two images - the direction and intensity.
 */
class SobelFilter : public Filter {
  public:
     /**
       * @brief Constructor for SobelFilter object
       */
    SobelFilter();
    /**
      * @brief Applies the sobel filter to the image(s) in original and populates the filtered with resulting image(s)
      *
      * @return NONE
      */
    void Apply(vector<Image*> original, vector<Image*> filtered);
};

#endif
