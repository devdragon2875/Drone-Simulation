
#ifndef ROBOTFACTORY_H_
#define ROBOTFACTORY_H_
/**
 * @file robot_factory.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "entity_factory.h"
#include <map>
#include <memory>
#include "robot.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class for a factory that creates hospital objects.
 * 
 *  
 */
class RobotFactory: public EntityFactory {
public:
    /**
      * @brief Constructor for factory. Assigns name.
      * 
      */ 
    RobotFactory(){this->name="robot";};
    /**
      * @brief Creates an enitity based on inputted JSON information
      * @return The desired entity.
      */
    RobotFactory(std::string name){this->name=name;}; //FOR TESTING ONLY
    Entity* CreateEntity(picojson::object& entityData){
        Robot* robot = new Robot();
        robot->id = entityData["entityId"].get<double>();

        // Get the position as an array
        picojson::array position = entityData["position"].get<picojson::array>();
        robot->pos[0] = position[0].get<double>();
        robot->pos[1] = position[1].get<double>();
        robot->pos[2] = position[1].get<double>();

        return robot;
    }
        /**
      * @brief Returns the name of the factory.
      * @return A string of the factory's name.
      */
    std::string getName(){return this->name;}
    
private:
    std::string name;
    std::map<std::string, std::unique_ptr<EntityFactory>> entityFactories;
};

#endif