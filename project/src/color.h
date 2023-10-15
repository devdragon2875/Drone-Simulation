/**
 * @file color.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

#ifndef COLOR_H_
#define COLOR_H_

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class to represent a pixel's color. Useful for converting unsigned chars to floating point values for floating point arithmetic. The class includes methods to
 * add, and divide using floating point arithmetic. As well as a function to return the luminance of a color object/pixel, which is useful for filters such as Double Threshold.
 * 
 *  
 */
class Color {
public:
    /**
      * @brief Default Constructor for the Color class. Sets each field to 0.
      * @return Constructs Color.
      */
    Color();
    /**
      * @brief Constructor for the Color class. Sets each field to the parameters passed in.
      * @return Constructs Color.
      */
    Color(unsigned char pixelRed,unsigned char pixelBlue,unsigned char pixelGreen,unsigned char pixelAlpha);
    /**
      * @brief Adds color parameters passed in to the Color class object it was called on. Each field is incremented by the respective parameters. Parameters are unsigned chars.
      * @return Nothing. Void function.
      */
    void Add(unsigned char pixelRed,unsigned char pixelBlue,unsigned char pixelGreen,unsigned char pixelAlpha);
    /**
      * @brief Adds color parameters passed in to the Color class object it was called on. Each field is incremented by the respective parameters. Parameters are floats.
      * @return Nothing. Void function.
      */
    void FloatAdd(float pixelRed, float pixelGreen, float pixelBlue, float pixelAlpha);
    /**
      * @brief Divides the class object's color fields by the respective values passed in. Each field is divided by the respective parameters.
      * @return Nothing. Void function.
      */
    void Divide(float d);
    /**
      * @brief Function to compute the luminance of a color class object.
      * @return Luminance of the color class object, float.
      */
    float red,blue,green,alpha;
    float getL() const;

};
#endif