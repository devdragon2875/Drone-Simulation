/**
 * @file blob_detection_filter.cc
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
#include "blob_detection_filter.h"

void BlobDetectionFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    *filtered[0]=*original[0];
    int width=original[0]->GetWidth();
    int height=original[0]->GetHeight();
    float L;
    int values[4];

    //Loop over every pixel. At each pixel calculate the luminance. Use a color class to convert every field of the pixel to the luminance to produce greyscale.
    //#pragma omp parallel for
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            unsigned char* pixel=original[0]->GetPixel(x,y);
            if(pixel[0]>=155 && pixel[1]>85 && pixel[1]<165 && pixel[2]<50){ //Threshold for orange, the color of the robot. Set to all white if a qualifying pixel.
                Color c1(255,255,255,255);
                filtered[0]->SetPixel(x,y,&c1);
            }
            else{ //Not a qualifying pixel, set to black.
                Color c2(0,0,0,255);
                filtered[0]->SetPixel(x,y,&c2);
            } 
        }
    }


}
    

