#ifndef IMAGEPROCESSOR_H_
#define IMAGEPROCESSOR_H_
/**
 * @file imageProcessor.h
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
#include "greyscale_filter.h"
#include "double_threshold_filter.h"

using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for our Image Processor. Contains a vector of filters to which it uses to do tasks such as Canny Edge Detection. Filters are stored as a mapping from strings to filter objects.
 * Multiple applications of filters are grouped into functions. For example, to apply Canny Edge Detection, one would call the Canny_Edge function.
 * 
 *  
 */
class ImageProcessor {
public:
/**
      * @brief Default constructor. Initializes vector of filters available to the image processor.
      * @return Constructs the Image Processor.
      */
ImageProcessor();
/**
      * @brief This function performs Canny Edge detection, utilizing the filters in the class vector of filters. How it works: the function applies one filter, saves the result, and passes it to the next. 
      * The filter/function also converts the pixels back from floats to unsigned chars.
      * @return Nothing. Void function.
      */
void Apply(string filter,std::vector<Image*> original, std::vector<Image*> filtered);

void AddFilter(Filter* filter,const std::string& type);
private:
std::map<std::string, unique_ptr<Filter>> filters;

};

#endif
