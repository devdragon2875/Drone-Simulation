#ifndef CANNYEDGEFILTER_H_
#define CANNYEDGEFILTER_H_

/**
 * @file canny_edge_filter.h
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
 * Class for the Canny Edge filter. Apply method applies Canny Edge Detection, which uses multiple filters, stored in a map object in this class.
 * 
 *  
 */
class CannyEdgeFilter : public Filter {
public:
/**
      * @brief Constructs the Canny Edge Filter.
      * @return Nothing.
      */
CannyEdgeFilter();
/**
      * @brief This function performs Canny Edge detection, utilizing the filters in the class vector of filters. How it works: the function applies one filter, saves the result, and passes it to the next. 
      * The filter/function also converts the pixels back from floats to unsigned chars.
      * @return Nothing. Void function.
      */
void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
private:
std::map<std::string, unique_ptr<Filter>> filters;

};

#endif