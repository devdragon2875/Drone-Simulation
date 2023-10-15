/**
 * @file double_threshold_filter.cc
 *
 * @copyright 2021 3081W, Group 21, Author: Robert Maple All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include <vector>
#include "double_threshold_filter.h"

DoubleThresholdFilter::DoubleThresholdFilter(float high,float low)
{
    thresholdRatioHigh=high;
    thresholdRatioLow=low;
}

void DoubleThresholdFilter::Apply(vector<Image*> original, vector<Image*> filtered){
    *filtered[0]=*original[0]; //Intializes the filtered image.

    //Initialize variables
    int width=original[0]->GetWidth();
    int height=original[0]->GetHeight();
    float L=0;
    float maxL=0;
    float thresholdHigh,thresholdLow;
    Color c1;

    //Find the highest Luminance pixel.
    //#pragma omp parallel for
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            float value=original[0]->getPixelFloat(x,y);
            c1.red=value/255.0;
            c1.green=value/255.0;
            c1.blue=value/255.0;
            c1.alpha=value/255.0;
            L=c1.getL(); 
            if(L>maxL)
            {
                maxL=L;
            }
        }
    }
    
    //Set the high threshold and low threshold.
    thresholdHigh=maxL*thresholdRatioHigh;
    thresholdLow=thresholdHigh*thresholdRatioLow;

    //Loop over each pixel. Calculate the luminance, if the luminance is above the highest threshold, set to 255, if between 2 thresholds, set to 25, otherwise set to 0.
    //#pragma omp parallel for
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            float value=original[0]->getPixelFloat(x,y);
            c1.red=value/255.0;
            c1.green=value/255.0;
            c1.blue=value/255.0;
            c1.alpha=value/255.0;
            L=c1.getL(); 
            if(L>thresholdHigh)
            {
                filtered[0]->setPixelFloat(x,y,255.0f);
            }
            else if(L<thresholdHigh && L>thresholdLow){
                filtered[0]->setPixelFloat(x,y,25.0f);
            }
            else{
                filtered[0]->setPixelFloat(x,y,0.0f);
            }
        }
    }
   
    
}
