/**
 * @file image.cc
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <string>
#include "image.h"
#include "color.h"

using namespace std;

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Image::Image()
{
    this->width=0;
    this->height=0;
    this->components=4;
    this->image = new unsigned char[1]; 
}

Image::Image(int width, int height){
    this->width=width;
    this->height=height;
    this->components=4;
    this->image = new unsigned char[width*height*components];
}

Image::Image(const char* filename){
    unsigned char *loadedImage = stbi_load(filename, &width, &height, &components, STBI_rgb_alpha);
    components = 4;
    image = new unsigned char[width*height*components];
    std::copy(loadedImage, loadedImage + width*height*components, image); 
    stbi_image_free(loadedImage);
}

Image::Image(const Image& im){
    image=NULL;
    *this=im;
}

Image::~Image(){
    delete[] image;
}

void Image::operator=(const Image& im){
    this->height=im.height;
    this->width=im.width;
    this->components=im.components;
    delete[] this->image;
    this->image=new unsigned char[im.width*im.height*im.components];
    for(int i=0; i<(im.width*im.height*im.components);i++){
        this->image[i]=im.image[i];
    }
}

void Image::SaveAs(const char* filename){
    stbi_write_png(filename, width, height, components, image, width*4);
}

int Image::GetHeight(){
    return height;
}

int Image::GetWidth(){
    return width;
}

int Image::GetComponentNum(){
    return components;
}

unsigned char* Image::GetPixel(int x,int y){
    return &image[(y*width + x)*4];
}

void Image::SetPixel(int x, int y,Color* color){
    unsigned char* toSet=&image[(y*width + x)*4];
    toSet[0] = color->red*255;
    toSet[1] = color->green*255;
    toSet[2] = color->blue*255;      
    toSet[3] = color->alpha*255;
}

float Image::getPixelFloat(int x, int y) const {
    unsigned char* pixel = &image[(x + width*y)*4];
    return (*reinterpret_cast<float*>(pixel));
}

void Image::setPixelFloat(int x, int y, float value){
    unsigned char* pixel = &image[(x + width*y)*4];
    *reinterpret_cast<float*>(pixel) = value;
}
