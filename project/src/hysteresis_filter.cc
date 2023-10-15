/*
 * @file hysteresis_filter.cc
 */

/*
 * Includes
 */

#include "hysteresis_filter.h"
#include "image.h"
#include <vector>
#include "color.h"

/*
 * Member Definitions
 */

HysteresisFilter::HysteresisFilter()
{

}

void HysteresisFilter::Apply(vector<Image*> original, vector<Image*> filtered){
    *filtered[0]=*original[0];

    int width=original[0]->GetWidth();
    int height=original[0]->GetHeight();
    float L;
    int values[4];
    float weak = 25;
    float strong = 255;

	//#pragma omp parallel for
    for (int x = 1; x < width-1; x++) {
        for (int y = 1; y < height-1; y++) {
		float pixel=original[0]->getPixelFloat(x,y);
		if(pixel == weak){
			bool strongPixel = false;
			for(int i = -1; i <= 1; i++){
				for(int j = -1; j <= 1; j++){
					float edgePixel =original[0]->getPixelFloat(x+i,y+j);
					if(edgePixel == strong){
						strongPixel = true;
					}
				}
			}
			if(strongPixel){
            			filtered[0]->setPixelFloat(x,y,255);
			} else {
                                filtered[0]->setPixelFloat(x,y,0);

			}

		}
		
        }
    }


}

