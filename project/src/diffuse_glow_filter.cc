/*
 * @file diffuse_glow_filter.cc
 */

/*
 * Includes
 */

#include "diffuse_glow_filter.h"
#include "image.h"
#include <vector>
#include "color.h"
#include <math.h>

/*
 * Member Functions
 */
DiffuseGlowFilter::DiffuseGlowFilter(){
	radius = 10;
	intensity = 50;
}

DiffuseGlowFilter::DiffuseGlowFilter(int r, float i)
{
	radius = r;
	intensity = i;
}

void DiffuseGlowFilter::Apply(vector<Image*> original, vector<Image*> filtered){
    *filtered[0]=*original[0];

    int width=original[0]->GetWidth();
    int height=original[0]->GetHeight();
    float L;
    int values[4];
	#pragma omp parallel for
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            unsigned char* pixel=original[0]->GetPixel(x,y);
            Color c1(pixel[0],pixel[1],pixel[2],pixel[3]);

	    for(int i = 0; i < radius; i++){
	    	for(int j = 0; j < radius; j++){
			if(x+i < width && x-i > 0 && y+j < height && y-j > 0){
				float hypot = sqrt((i * i) + (j * j));
				if(hypot < radius){
					unsigned char* pixelNew = original[0]->GetPixel(x+i,y+j);
            				Color c2(pixel[0],pixel[1],pixel[2],pixel[3]);
            				float L2 =c2.getL();
					float scale = 0;
					if(intensity > 0){
						scale = 255*L2 * hypot/(radius*intensity);
					} 
					
					
					c1.Add(scale, scale, scale, 0);

				}
			}
		}
	    }

	    if(c1.red > 1){
	    	c1.red = 1;
	    }

	    if(c1.blue > 1){
	    	c1.blue = 1;
	    }

	    if(c1.green > 1){
	    	c1.green = 1;
	    }
            
            filtered[0]->SetPixel(x,y,&c1);
        }
    }


}

