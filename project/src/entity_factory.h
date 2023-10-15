
#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

/**
 * @file entity_factory.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity.h"
#include <string>
#include <picojson.h>
#include "camera_controller.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for the Entity Factory. This is the parent class for all Entity Factories. Abstract.
 * 
 *  
 */

class EntityFactory {
public:
    /**
      * @brief Virtual Destructor.
      *
      * @return Nothing. 
      */
    virtual ~EntityFactory(){};
    /**
      * @brief This virtual function takes in JSON entityData, then uses that to produce a new Entity object.
      *
      * @return Entity* pointer to a new drone. 
      */
    virtual Entity* CreateEntity(picojson::object& entityData,ICameraController& cameraController){Entity* e; return e;};
    /**
      * @brief Function to return the name of the factory.
      *
      * @return String. Name of the factory.
      */
    virtual std::string getName()=0;
protected:
    std::string name;
};
#endif