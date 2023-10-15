/**
 * @file sobel_filter.cc
 *
 * @copyright 2021 3081W, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sobel_filter.h"
#include "image.h"
#include <vector>
#include <cmath>

SobelFilter::SobelFilter() {}

void SobelFilter::Apply(vector<Image*> original, vector<Image*> filtered) {
  int width = original[0]->GetWidth();
  int height = original[0]->GetHeight();

  //Convert Pixel to Float
  //#pragma omp parallel for
  for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            unsigned char* value=original[0]->GetPixel(x,y);
            //Note: this is only considering the red value because it is expecting a greyscale image
            original[0]->setPixelFloat(x,y,value[0]*1.0);
        }
    }

  *filtered[0] = *original[0];
  *filtered[1] = *original[0];

  float Kx[3][3] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
  float Ky[3][3] = {1, 2, 1, 0, 0, 0, -1, -2, -1};

  Image xDirection;
  xDirection = *original[0];

  Image yDirection;
  yDirection = *original[0];

  //#pragma omp parallel for
  for(int i = 1; i < width-1; i++) {
    for(int j = 1; j < height-1; j++) {
      Color xColor(0,0,0,1);
      Color yColor(0,0,0,1);

      int ki = 0;                                  //kernel row index value
      for(int k = i-1; k <= i+1; k++) {

        int kj = 0;                                //kernel col index value
        for(int l = j-1; l <= j+1; l++) {
    	    float pixel = original[0]->getPixelFloat(k, l);

          float xVal = Kx[ki][kj]*pixel;
          float yVal = Ky[ki][kj]*pixel;

          xColor.FloatAdd(xVal, xVal, xVal, 0);
          yColor.FloatAdd(yVal, yVal, yVal, 0);

          kj++;
        }
        ki++;
      }
      xDirection.setPixelFloat(i, j, xColor.red*255);
      yDirection.setPixelFloat(i, j, yColor.red*255);
    }
  }
  
  //#pragma omp parallel for
  for(int i = 1; i < width-1; i++) {
   for(int j = 1; j < height-1; j++) {
     float x = xDirection.getPixelFloat(i, j);
     float y = yDirection.getPixelFloat(i, j);

     float G = sqrt((x*x) + (y*y)); //direction
     if(G<0) { G = 0; }
     if (G>255) { G = 255; }
     filtered[0]->setPixelFloat(i, j, G);

     float theta = atan2(y, x); //intensity
     filtered[1]->setPixelFloat(i, j, theta*255);
   }
  }
}
