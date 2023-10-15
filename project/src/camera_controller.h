#ifndef ICAMERA_CONTROLLER_H_
#define ICAMERA_CONTROLLER_H_

/**
 * @file camera_controller.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "picojson.h"

/// A raw camera image stored in jpg format (data) and length is an int
struct RawCameraImage {
    const unsigned char* data;
    int length;
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Abstract class for the info resulting from image processing done on a picture taken by the drone's camera.
 * 
 *  
 */

/// The result returned from the image processing
class ICameraResult {
public:
    /**
      * @brief Destructor.
      *
      * @return Nothing. Destructor.
      */
    virtual ~ICameraResult() {}
};

/**
 * @brief Abstract class for the observer of all cameras. Processes images and returns results.
 * 
 *  
 */
class ICameraObserver {
public:
    /**
      * @brief Destructor.
      *
      * @return Nothing. Destructor.
      */
    virtual ~ICameraObserver() {}
    /**
      * @brief This function processes images asynchronously. 
      *
      * @return ICameraResult object, with info from Image Processing.
      */
    virtual ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const = 0;
    /**
      * @brief After asynchronous image processing is complete, this function is called to update the simulation.
      *
      * @return Nothing. Void function.
      */
    virtual void ImageProcessingComplete(ICameraResult* result) = 0;
};

/**
 * @brief Abstract class for the controller of the drone's camera.
 * 
 *  
 */
class ICameraController {
public:
    /**
      * @brief Destructor.
      *
      * @return Nothing. Destructor.
      */
    virtual ~ICameraController() {}
    /**
      * @brief Takes a picture. After this is called, the image will be add more to the image processing queue to be processed.
      *
      * @return Nothing. Void.
      */
    virtual void TakePicture(int cameraId) = 0;
    /**
      * @brief Adds an observer to the camera controller.
      *
      * @return Nothing. Void.
      */
    virtual void AddObserver(ICameraObserver& observer) = 0;
    /**
      * @brief Removes an observer to the camera controller.
      *
      * @return Nothing. Void.
      */
    virtual void RemoveObserver(ICameraObserver& observer) = 0;
};

#endif
