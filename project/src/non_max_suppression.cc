/**
 * @file non_max_suppression.cc
 */
/*******************************************************************************
* Includes
******************************************************************************/
#include "non_max_suppression.h"
#include "image.h"
#include <vector>
#include "color.h"
#include "math.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
NonMaxSuppression :: NonMaxSuppression(){

}

void NonMaxSuppression :: Apply(vector<Image*> original, vector<Image*> filtered){
    *filtered[0] = *original[0]; //!< filtered image starts as copy of intensity image
    
    int width = original[0]->GetWidth();
    int height = original[0]->GetHeight();

    //#pragma omp parallel for
    for (int x = 1; x < width-1; x++) {
        for (int y = 1; y < height-1; y++) {

            float anglePixel = original[1]->getPixelFloat(x,y); //!< represent direction image pixel as float
            float angle = anglePixel * 180.0 / M_PI ; //!< convert angle to degrees

            
            if (angle < 0){
                angle += 180; //!< make angle positive if negative
            }
            
            float originalPixel = original[0]->getPixelFloat(x,y); //!< represent intensity image pixel as float

            float q = 255; //!< intensity value in one direction
            float r = 255; //!< intesntiy value in opposite direction

            if ((0 <= angle < 22.5) or (157.5 <= angle <= 180)){ //!< check direction based on angle
                q = original[0]->getPixelFloat(x, y+1);
                r = original[0]->getPixelFloat(x, y-1);
            }
            else if (22.5 <= angle < 67.5){ //!< check direction based on angle
                q = original[0]->getPixelFloat(x+1, y-1);
                r = original[0]->getPixelFloat(x-1, y+1);
            }
            else if (67.5 <= angle < 112.5){ //!< check direction based on angle
                q = original[0]->getPixelFloat(x+1,y);
                r = original[0]->getPixelFloat(x-1, y);
            }
            else if (112.5 <= angle < 157.5){ //!< check direction based on angle
                q = original[0]->getPixelFloat(x-1, y-1);
                r = original[0]->getPixelFloat(x+1, y+1);
            }

           if ((originalPixel >= q) and (originalPixel >= r)){ //!< check intensity of neighbor vs original
               filtered[0]->setPixelFloat(x,y,originalPixel); //!< set filtered pixel intensity to orignal intensity
           }
           else{
               filtered[0]->setPixelFloat(x,y,0); //!< set filtered pixel intensity to 0
           }
        }
    }
}