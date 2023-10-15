/*
 * @file hysteresis_filter.h
 */
#ifndef HYSTERESIS_FILTER_H_
#define HYSTERESIS_FILTER_H_

/*
 * Includes
 */
#include "filter.h"
#include <vector>

/*
 * @brief This class create a hysteresis filter. This filter makes edges to be more or less defined based on the surrounding pixels' strength.
 */
class HysteresisFilter : public Filter {
    public:
/*
 * @brief This is the default constructor.
 */
	HysteresisFilter();
/*
 * @brief This applies the hysteresis filter to the input of original and stores it in filtered. The filter looks at the surrounding pixels and if there is a strong pixel, the pixel is made to be strong. Else, it is weak.
 */
    	void Apply(vector<Image*> original, vector<Image*> filtered);
};

#endif
