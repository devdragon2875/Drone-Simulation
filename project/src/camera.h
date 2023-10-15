#ifndef CAMERA_H_
#define CAMERA_H_

/**
 * @file camera.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "web_app.h"
#include <fstream>
#include "util/base64.h"
#include "imageProcessor.h"
#include "cmath"
//Struct to store the result of analyzing a picture.
struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for the Camera, which is a ICameraObserver.
 *
 *
 */

class Camera : public ICameraObserver {
public:
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    }resultStruct;

    /**
      * @brief Constructor.
      *
      * @return Nothing. 
      */
    Camera(int cameraId, ICameraController* controller);
    /**
      * @brief Takes a picture. After this is called, the image will be add more to the image processing queue to be processed.
      *
      * @return Nothing. Void.
      */
    void TakePicture();
    /**
      * @brief This function processes images asynchronously. This function applies a blob detection and canny edge filter to the image next up in the image processing queue.
      * The function compares the amount of blob pixels, to the amount blob pixels that are also canny edge pixels, and then determines if the robot has been found.
      * If the robot has been found, the location of the robot is found using a depth image.
      *
      * @return ICameraResult object, with info from Image Processing. Contains coordinates of the robot.
      */
    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const;

    /**
      * @brief After asynchronous image processing is complete, this function is called to update the simulation.
      *
      * @return Nothing. Void function.
      */
    void ImageProcessingComplete(ICameraResult* result);
private:
    ICameraController* controller;
    int id;
};

#endif
