
#ifndef COMPOSITEENTITYFACTORY_H_
#define COMPOSITEENTITYFACTORY_H_
/**
 * @file composite_entity_factory.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "entity_factory.h"
#include <map>
#include <memory>
#include <picojson.h>
#include "drone_factory.h"
#include "robot_factory.h"
#include "charging_station_factory.h"
#include "hospital_factory.h"
#include "camera_controller.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for the Composite Entity Factory. Is an EntityFactory, and has Entityfactories. Can produce Entity's, as well as add new factories. Closed to change, open to extension.
 * 
 *  
 */

class CompositeEntityFactory: public EntityFactory {
public:
    /**
      * @brief Constructor.
      *
      * @return Nothing. 
      */
    CompositeEntityFactory(){
        //Initialize all of our existing factories.
        this->entityFactories["drone"] = std::unique_ptr<EntityFactory>(new DroneFactory());
        this->entityFactories["robot"] = std::unique_ptr<EntityFactory>(new RobotFactory());
        this->entityFactories["recharge station"] = std::unique_ptr<EntityFactory>(new ChargingStationFactory());
        this->entityFactories["hospital"] = std::unique_ptr<EntityFactory>(new HospitalFactory());
    }
    /**
      * @brief This function takes in JSON entityData, uses that to determine which factory in it's map to use, and then uses that factory to create and return an entity.
      *
      * @return Entity* pointer to a new entity. 
      */
    Entity* CreateEntity(picojson::object& entityData,ICameraController& cameraController);
    /**
      * @brief This function takes in an arbritrary EntityFactory* factory object, and adds it to the map entityFactories. This makes the composite factory open to extensions.
      *
      * @return Nothing. Void.
      */
    void AddFactory(EntityFactory* factory);
    /**
      * @brief Returns the name of a factory.
      *
      * @return String. Name of factory.
      */
    std::string getName(){return this->name;}
    /**
      * @brief Returns the name of a factory by using the composite's map, for testing purposes only.
      *
      * @return String. Name of factory.
      */
    std::string checkFactory(std::string name); //FOR TESTING OF ADDFACTORY ONLY
private:
    std::string name;
    std::map<std::string, std::unique_ptr<EntityFactory>> entityFactories;
};

#endif
