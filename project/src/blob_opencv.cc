/**
 * @file blob_opencv.cc
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
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
#include "blob_opencv.h"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <fstream>

void BlobDetectOpenCVFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    
    original[0]->SaveAs("input.jpg"); 

    cv::Mat original_img = cv::imread("input.jpg");
    cv::Mat output_img;

    cv::inRange(original_img, cv::Scalar(0,85,155), cv::Scalar(50,165,255),output_img);
    cv::imwrite("blob.jpg", output_img);

}
    

