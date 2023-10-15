/**
 * @file imageProcessor.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"
#include "filter.h"
#include "greyscale_filter.h"
#include "non_max_suppression.h"
#include "double_threshold_filter.h"
#include "hysteresis_filter.h"
#include "imageProcessor.h"
#include "gaussian_blur_filter.h"
#include "sobel_filter.h"
#include "invert.h"
#include "canny_edge_filter.h"
#include "blob_detection_filter.h"
#include "blob_opencv.h"


using namespace std;

ImageProcessor::ImageProcessor(){
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian_blur"] = unique_ptr<Filter>(new GaussianBlurFilter());
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSuppression());
    filters["double_threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(0.35f,0.10f));
    filters["hysteresis"] = unique_ptr<Filter>(new HysteresisFilter());
    filters["canny-edge-detect"] = unique_ptr<Filter>(new CannyEdgeFilter());
    filters["blob-detect"]=unique_ptr<Filter>(new BlobDetectionFilter());
    filters["blob-opencv"]=unique_ptr<Filter>(new BlobDetectOpenCVFilter());
}

void ImageProcessor::AddFilter(Filter* filter,const std::string& type){
    this->filters[type] = std::unique_ptr<Filter>(filter);
}

void ImageProcessor::Apply(string filter,std::vector<Image*> original, std::vector<Image*> filtered){
    this->filters[filter]->Apply(original,filtered);
}
