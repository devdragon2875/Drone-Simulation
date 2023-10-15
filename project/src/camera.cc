/**
 * @file blob_detection_filter.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "camera.h"
#include "camera_controller.h"

Camera::Camera(int cameraId, ICameraController* controller) : id(id), controller(controller) {
    controller->AddObserver(*this);
}

void Camera::TakePicture(){
    controller->TakePicture(id);
}

ICameraResult* Camera::ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
    if (cameraId == id || cameraId < 0) {
        //Save the files from the camera. These will then be used by the Image Processor below.
        std::ofstream colorFile ("color.jpg", std::ios::out | std::ios::binary);
        colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
        std::ofstream depthFile ("depth.jpg", std::ios::out | std::ios::binary);
        depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);

        ImageProcessor processor;
        //BLOB DETECT: Here we perform blob detection on the regular image from the drone, and save the result.
        string inputFile=("color.jpg");
        Image input1(inputFile.c_str());
        std::vector<Image*> inputs1;
        std::vector<Image*> outputs1;
        inputs1.push_back(&input1);
        processor.Apply("blob-opencv",inputs1,outputs1);
        Image output1("blob.jpg");
        outputs1.push_back(&output1);
        
        //CANNY EDGE DETECT: Here we perform canny edge detection on the regular image from the drone, and save the result.
        inputFile=("color.jpg");
        Image input2(inputFile.c_str());
        Image output2;
        std::vector<Image*> inputs2;
        std::vector<Image*> outputs2;
        inputs2.push_back(&input2);
        outputs2.push_back(&output2);
        processor.Apply("canny-edge-detect",inputs2,outputs2);
        std::string outputFile="cannyPixels.jpg";
        output2.SaveAs(outputFile.c_str());

        //Variables for scanning and counting pixels.
        int width=outputs1[0]->GetWidth();
        int height=outputs1[0]->GetHeight();
        int blobCount=0;
        int cannyCount=0;
        //COMPARE PIXEL COUNTS: Here, we check for each blob pixel, if it is also an edge pixel.  
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                unsigned char* pixel1=outputs1[0]->GetPixel(x,y);
                
                if(pixel1[1]==255){ //Check to see if this is a blob pixel.
                    blobCount++;
                    unsigned char* pixel2=outputs2[0]->GetPixel(x,y);
                    if(pixel2[1]==255){ //Check to see if this is an edge pixel.
                        cannyCount++;
                    }
                }

            }
        }
        //DETERMINE IF THIS IS A BLOB: 
        if(blobCount>(7*cannyCount) && cannyCount>10){ //This is the ratio used to determine if the blob we detected is actually a blob, or just a collection of edges.
            //Variables for depth calculations
            double xDir;
            double yDir;
            double zDir;
            double distance;
            //Construct Image classes for our two input images.
            Image depth("depth.jpg");
            Image blob("blob.jpg");
            //Variable to track if we are performing the first depth calculation.
            bool firstCalc=true;
            //Generate the result of image processing.  This could include images using the Result class.
            CameraResult* result = new CameraResult();
            //DEPTH/LOCATION CALCULATION: Here, we use the depth image in conjunction with the blob image to average out an approximate location for the robot.
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    unsigned char* pixel1=depth.GetPixel(x,y); //Depth pixel
                    unsigned char* pixel2=blob.GetPixel(x,y); //Blob pixel
                    if(pixel2[0]==255){ //If a blob pixel, use this pixel to calculate depth/location, using equations provided on the Iteration 2 document.
                        Color c(pixel1[0],pixel1[1],pixel1[2],pixel1[3]);
                        xDir=2.0*(c.red-0.5);
                        yDir=2.0*(c.green-0.5);
                        zDir=2.0*(c.blue-0.5);
                        double magnitude=sqrt(pow(xDir,2)+pow(yDir,2)+pow(zDir,2));
                        distance=(1-magnitude)*50;
                        xDir=xDir/magnitude;
                        yDir=yDir/magnitude;
                        zDir=zDir/magnitude;
                    }
                    if(firstCalc==false){ //If this is not the first depth calculation, then we can average with the previous result.
                        result->pos[0] = (result->pos[0]+xPos+(xDir*distance))/2;
                        result->pos[1] = (result->pos[1]+yPos+(yDir*distance))/2;
                        result->pos[2] = (result->pos[2]+zPos+(zDir*distance))/2;
                    }
                    else{ //If we enter this, we are looking at the first blob pixel, and thus can't average the result.
                        result->pos[0]=xPos+(xDir*distance);
                        result->pos[1]=yPos+(yDir*distance);
                        result->pos[2]=zPos+(zDir*distance);
                        firstCalc=false;
                    }
                }
            }
            result->found = true;
            return result;
        }
        else{
            //No blob, return a return->found=false.
            CameraResult* result = new CameraResult();
            result->found = false;
            result->pos[0] = xPos;
            result->pos[1] = yPos;
            result->pos[2] = zPos;
            return result;
        }
    }
    else {
        return NULL;
    }
}

void Camera::ImageProcessingComplete(ICameraResult* result) {
    CameraResult& res = *static_cast<CameraResult*>(result);
    if (res.found) {
        std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[2] << std::endl;
    }
    delete result;
}