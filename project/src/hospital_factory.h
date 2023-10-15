
#ifndef HOSPITALFACTORY_H_
#define HOSPITALFACTORY_H_
/**
 * @file hospital_factory.h
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
#include "hospital.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class for a factory that creates hospital objects.
 * 
 *  
 */
class HospitalFactory: public EntityFactory {
public:
/**
      * @brief Constructor for factory. Assigns name.
      * 
      */ 
    HospitalFactory(){this->name="hospital";};
      /**
      * @brief Creates an enitity based on inputted JSON information
      * @return The desired entity.
      */
    Entity* CreateEntity(picojson::object& entityData){
        Hospital* hospital = new Hospital();
        hospital->id = entityData["entityId"].get<double>();

        // Get the position as an array
        picojson::array position = entityData["position"].get<picojson::array>();
        hospital->pos[0] = position[0].get<double>();
        hospital->pos[1] = position[1].get<double>();
        hospital->pos[2] = position[1].get<double>();

        return hospital;
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