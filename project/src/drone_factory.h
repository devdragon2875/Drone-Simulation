#ifndef DRONEFACTORY_H_
#define DRONEFACTORY_H_
/**
 * @file drone_factory.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple, code also used from the code provided to us.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity.h"
#include "entity_factory.h"
#include <map>
#include <memory>
#include "drone.h"
#include "camera.h"
#include "camera_controller.h"
#include "electrical_entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for the Drone Factory. Is an EntityFactory, produces drones. 
 * 
 *  
 */

class DroneFactory: public EntityFactory {
public:
    /**
      * @brief Constructor. Assigns the drone factory's name.
      *
      * @return Nothing. 
      */
    DroneFactory();
    /**
      * @brief This function takes in JSON entityData, then uses that to produce a new drone object.
      *
      * @return Drone* pointer to a new drone. 
      */
    Entity* CreateEntity(picojson::object& entityData,ICameraController& cameraController);
    /**
      * @brief Function to return the name of the factory.
      *
      * @return String. Name of the factory.
      */
    std::string getName();
private:
    std::string name;
};

#endif