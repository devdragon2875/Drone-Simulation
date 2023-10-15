#ifndef BLOB_CV_H_
#define BLOB_CV_H_
/**
 * @file blob_opencv.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
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
 * @brief Class for the blob detection filter using OpenCV. Apply method applies blob detection filter.
 *
 * 
 *  
 */
class BlobDetectOpenCVFilter : public Filter {
    public:
    /**
      * @brief This function applies the blob detection filter to an image.
      * @return Nothing. Void function.
      */
        void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif