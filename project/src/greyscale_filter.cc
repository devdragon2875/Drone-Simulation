/**
 * @file greyscale_filter.cc
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */
 
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "greyscale_filter.h"
#include "image.h"
#include <vector>
#include "color.h"

GreyScaleFilter::GreyScaleFilter()
{

}

void GreyScaleFilter::Apply(vector<Image*> original, vector<Image*> filtered){
    *filtered[0]=*original[0]; //Initialize filtered image.
    
    int width=original[0]->GetWidth();
    int height=original[0]->GetHeight();
    float L;
    int values[4];

    //Loop over every pixel. At each pixel calculate the luminance. Use a color class to convert every field of the pixel to the luminance to produce greyscale.
    #pragma omp parallel for
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            unsigned char* pixel=original[0]->GetPixel(x,y);
            Color c1(pixel[0],pixel[1],pixel[2],pixel[3]);
            L=c1.getL(); 
            c1.red=L;
            c1.green=L;
            c1.blue=L;
            c1.alpha=(1.0*pixel[3])/255.0;
            filtered[0]->SetPixel(x,y,&c1);
        }
    }


}
