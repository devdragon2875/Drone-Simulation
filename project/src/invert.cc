/**
 * @file invert.cc
 */
/*******************************************************************************
* Includes
******************************************************************************/
#include "invert.h"
#include "image.h"
#include <vector>
#include "color.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Invert :: Invert(){

}

void Invert :: Apply(vector<Image*> original, vector<Image*> filtered){
    *filtered[0] = *original[0];

    int width = original[0]->GetWidth();
    int height = original[0]->GetHeight();
    
    #pragma omp parallel for
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            unsigned char* originalPixel = original[0]->GetPixel(x,y);
            Color invertedColor = Color(255-originalPixel[0], 255-originalPixel[1], 255-originalPixel[2],originalPixel[3]);
            filtered[0]->SetPixel(x, y, &invertedColor);
        }
    }
}