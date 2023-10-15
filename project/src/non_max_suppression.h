/**
 * @file non_max_suppression.h
 */

#ifndef NON_MAX_H
#define NON_MAX_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class that represents the "Non-Max Suppression" filter step of the
 *        Canny Edge Detection algorithm
 */
class NonMaxSuppression : public Filter{
    
    public:
/**
  * @brief Default constructor
  */
        NonMaxSuppression();
/**
  * @brief Applies the filter to an image input vector "original" which contains a 
  *        direction and intensity image within
  */
        void Apply(vector<Image*> original, vector<Image*> filtered);
};

#endif