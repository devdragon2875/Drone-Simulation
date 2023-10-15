/**
 * @file color.cc
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

 /*******************************************************************************
 * Includes
 ******************************************************************************/
#include "color.h"

Color::Color(){
    red=0.0;
    blue=0.0;
    green=0.0;
    alpha=0.0;
}

Color::Color(unsigned char pixelRed,unsigned char pixelGreen,unsigned char pixelBlue,unsigned char pixelAlpha){
    red=(1.0*(pixelRed))/255.0;
    green=(1.0*(pixelGreen))/255.0;
    blue=(1.0*(pixelBlue))/255.0;
    alpha=(1.0*(pixelAlpha))/255.0;
}

void Color::Add(unsigned char pixelRed,unsigned char pixelGreen,unsigned char pixelBlue,unsigned char pixelAlpha){
    red=red+(1.0*(pixelRed)/255.0);
    green=green+(1.0*(pixelGreen)/255.0);
    blue=blue+(1.0*(pixelBlue)/255.0);
    alpha=alpha+(1.0*(pixelAlpha)/255.0);
}

void Color::Divide(float d){
    red=red/d;
    blue=blue/d;
    green=green/d;
    alpha=alpha/d;
}

void Color::FloatAdd(float pixelRed, float pixelGreen, float pixelBlue, float pixelAlpha) {
  red=red+(pixelRed/255.0);
  green=green+(pixelGreen/255.0);
  blue=blue+(pixelBlue/255.0);
  alpha=alpha+(pixelAlpha/255.0);
}

float Color::getL() const{
    return 0.2126*red + 0.7152*green + 0.0722*blue;
}