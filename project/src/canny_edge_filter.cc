/**
 * @file canny_edge_filter.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved.
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
#include "non_max_suppression.h"
#include "double_threshold_filter.h"
#include "hysteresis_filter.h"
#include "canny_edge_filter.h"
#include "gaussian_blur_filter.h"
#include "sobel_filter.h"
#include "invert.h"


using namespace std;

CannyEdgeFilter::CannyEdgeFilter(){
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian_blur"] = unique_ptr<Filter>(new GaussianBlurFilter());
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSuppression());
    filters["double_threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(0.35f,0.10f));
    filters["hysteresis"] = unique_ptr<Filter>(new HysteresisFilter());
}

void CannyEdgeFilter::Apply(vector<Image*> original, vector<Image*> filtered){
    *filtered[0]=*original[0]; //Initializes the filtered image.
    std::vector<Image*> output; //Intermediate vector to assist in passing images to the next filter.
    Image i1; //Placeholders images in helper vector
    Image i2;
    output.push_back(&i1);
    output.push_back(&i2);
    int width=original[0]->GetWidth(); //Initialize dimensions for looping.
    int height=original[0]->GetHeight();
    Image temp; //Temp image to initialize the second part of filtered.
    filtered.push_back(&temp); //Initialize filtered[1]

    filters["greyscale"]->Apply(original,filtered);
    
    *output[0]=*filtered[0];
    filters["gaussian_blur"]->Apply(output,filtered);

    *output[0]=*filtered[0];
    filters["sobel"]->Apply(output,filtered);

    *output[0]=*filtered[0];
    *output[1]=*filtered[1];
    filters["non_max_suppression"]->Apply(output,filtered);
    
    *output[0]=*filtered[0];
    filters["double_threshold"]->Apply(output,filtered);

    *output[0]=*filtered[0];
    filters["hysteresis"]->Apply(output,filtered);
    

    //Convert float pixels back to unsigned chars.
    Color c1;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            float value=filtered[0]->getPixelFloat(x,y);
            c1.red=value/255.0;
            c1.green=value/255.0;
            c1.blue=value/255.0;
            c1.alpha=1;
            filtered[0]->SetPixel(x,y,&c1);
        }
    }
    
    
}
