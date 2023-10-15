/**
 * @file image.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

#ifndef IMAGE_H_
#define IMAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <string>
#include "color.h"

using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class to represent an Image. This class represents an Image as an unsigned char array. Image class objects can be constructed as blank with a set height and width, or based off 
 * an existing image. Images can make use of their copy constructor and equals operator functions to set equal to each other. The class also contains methods to get pixels as unsigned chars, 
 * or as represented as a float. For example, its necessary in the Sobel filter to represent the pixels as a single floating point value, so one must first convert the pixels from
 * unsigned chars to floats before using getPixelFloat().
 *
 * 
 *  
 */
class Image{
public:
    /**
      * @brief Default constructor. Sets width and height to zero, and the number of components to 4.
      * @return Constructs Image.
      */
    Image();
    /**
      * @brief Constructor that sets width and height of image.
      * @return Constructs Image.
      */
    Image(int width, int height);
    /**
      * @brief Constructor that loads an existing image, and sets fields of image accordingly.
      * @return Constructs Image.
      */
    Image(const char* filename);
      /**
      * @brief Copy constructor for the Image class.
      * @return Copies Image.
      */
    Image(const Image& im);
    /**
      * @brief Deconstructor for the image class.
      * @return Deconstructs any Filter.
      */
    ~Image();
    /**
      * @brief Equals operator for the Image class.
      * @return Void. Nothing.
      */
    void operator=(const Image& im);
    /**
      * @brief Function to save an image with the filename passed in.
      * @return Void. Nothing.
      */
    void SaveAs(const char* filename);
    /**
      * @brief Getter. Returns height of the image.
      * @return Height of the image.
      */
    int GetHeight();
    /**
      * @brief Getter. Returns width of the image.
      * @return Height of the width.
      */
    int GetWidth();
    /**
      * @brief Getter. Returns the number of components of the image.
      * @return Number of the components in the image. (Red,Blue,Green,Alpha).
      */
    int GetComponentNum();
    /**
      * @brief Getter. Returns the address of a pixel at x,y. Where x corresponds to width, and y corresponds to height.
      * @return Address of a pixel in image.
      */
    unsigned char* GetPixel(int x, int y);
    /**
      * @brief Setter. Sets the pixel to a certain color, at (x,y) to the values in the Color class passed in.
      * @return Height of the image.
      */
    void SetPixel(int x, int y, Color* pixel);
    /**
      * @brief Getter. Returns the floating point value of a pixel at position x,y. 
      * @return Float. Value of the pixel.
      */
    float getPixelFloat(int x, int y) const;
    /**
      * @brief Setter. Sets a pixel's bits to the floating point value passed in, at x,y
      * @return Nothing. Void function. 
      */
    void setPixelFloat(int x, int y, float value);
private:
    int height,width,components;
    unsigned char* image;
};

#endif
