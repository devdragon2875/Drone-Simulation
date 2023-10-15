#ifndef BLOBDETECTIONFILTER_H_
#define BLOBDETECTIONFILTER_H_

/**
 * @file blob_detection_filter.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"
#include "filter.h"

using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for the blob detection filter. Apply method applies double threshold filter.
 * 
 *  
 */
class BlobDetectionFilter : public Filter {
    public:
    /**
      * @brief Apply function. Applies a blob detection threshold to the image in "original" and stores the output in "filtered".
      *
      * @return Nothing. Void function.
      */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
