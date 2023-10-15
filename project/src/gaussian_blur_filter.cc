/**
 * @file gaussian_blur_filter.cc
 *
 * @copyright 2021 3081W, All rights reserved.
 */
 /*******************************************************************************
* Includes
******************************************************************************/
#include "gaussian_blur_filter.h"
#include "image.h"
#include <vector>
#include <cmath>
#include <math.h>

//HARD CODE: 3x3 Gaussian Kernel with Sigma 2.0
void GaussianBlurFilter::makeKernel(){
	int size = 1; //k=1 for 3x3 array
	float sigma = 2.0; //given

	float frontConstant = 1.0 / (2.0 * M_PI * (sigma*sigma));
	float denominator = 2.0 * (sigma*sigma);

	float numerator = 0.0;
	float sum = 0.0;

	//#pragma omp parallel for
	for(int x = -size; x <= size; x++) {
		for(int y = -size; y <= size; y++) {
			numerator = (x*x) + (y*y);
			kernel[x+size][y+size] = frontConstant * exp(-(numerator/denominator));
			sum += kernel[x+size][y+size];
		}
	}
	//#pragma omp parallel for
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			kernel[i][j] = kernel[i][j] / sum;
		}
	}
}

GaussianBlurFilter::GaussianBlurFilter() {
}

void GaussianBlurFilter::Apply(vector<Image*> original, vector<Image*> filtered) {
	*filtered[0] = *original[0];

	makeKernel();

	float sum = 0.0;
	//#pragma omp parallel for
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			sum += kernel[i][j];
		}
	}
	//#pragma omp parallel for
	for(int i = 1; i < original[0]->GetWidth()-1; i++) {
	 for(int j = 1; j < original[0]->GetHeight()-1; j++) {

		 Color color(0,0,0,255);

		 int ki = 0; //kernel row index
		 for(int k = i-1; k <= i+1; k++) {
			 int kj = 0; //kernel col index
    		for(int l = j-1; l <= j+1; l++) {
    			unsigned char* pixel = original[0]->GetPixel(k, l);
    			color.Add(kernel[ki][kj]*pixel[0], kernel[ki][kj]*pixel[1], kernel[ki][kj]*pixel[2], 0);
					kj++;
				}
				ki++;
    	}
			color.Divide(sum);

		 filtered[0]->SetPixel(i, j, &color);
	}
}

}
