/**
 * @file Entity.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */
#ifndef GAUSSIANBLURFILTER_H_
#define GAUSSIANBLURFILTER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include <vector>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Gaussian blur filter applies a gaussian kernel of 3x3 and sigma 2.0
 */

class GaussianBlurFilter : public Filter {
  public:
  /**
       * @brief Constructor for Gaussian Blur Filter object
       */
    GaussianBlurFilter();
    /**
       * @brief Applies the gaussian blur filter to image(s) in original and returns output in filtered
       *
       * @return NONE
       */
    void Apply(vector<Image*> original, vector<Image*> filtered);
  private:
    void makeKernel();
    float kernel[3][3];
};

#endif
