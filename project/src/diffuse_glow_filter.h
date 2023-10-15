/**
 * @file diffuse_glow_filter.h
 */

#ifndef DIFFUSEGLOW_FILTER_H_
#define DIFFUSEGLOW_FILTER_H_

/*
 * Includes
 */

#include "filter.h"
#include <vector>

/*
 * Class Definition
 */

/**
 * @brief Diffuse glow is a type of filter that diffuses a glow(seemingly making light sources brighter and have farther reach) at a given intensity and radius.
 */
class DiffuseGlowFilter : public Filter {	

public:
/*
 * @brief The default constructor. Sets the radius to 10 and intensity to 50.
 */
    DiffuseGlowFilter();
/*
 * @brief This constructor sets the radius and intensity to the arguments passed.
 * @param r An integer that correlates to the brightness of the light source(how white the pixel will look)
 * @param i A float that describes the intensity of a pixel(the diffused brightness)
 */
    DiffuseGlowFilter(int r, float i);

/*
 * @brief Apply takes in a vector of an Image and applies the radius at a certain intensity to each pixel. The resulting image is stored in filtered
 */
    void Apply(vector<Image*> original, vector<Image*> filtered);

private:
    int radius;
    float intensity;
};

#endif
               
