
#ifndef CHARGERFACTORY_H_
#define CHARGERFACTORY_H_
/**
 * @file charging_station_factory.h
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
#include "charging_station.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class for a factory that creates charging station objects.
 * 
 *  
 */
class ChargingStationFactory: public EntityFactory {
public:
  /**
      * @brief Constructor for factory. Assigns name.
      * 
      */  
    ChargingStationFactory(){this->name="recharge station";};
    /**
      * @brief Creates an enitity based on inputted JSON information
      * @return The desired entity.
      */
    Entity* CreateEntity(picojson::object& entityData){
        ChargingStation* charger = new ChargingStation();
        charger->id = entityData["entityId"].get<double>();
        
        // Get the position as an array
        picojson::array position = entityData["position"].get<picojson::array>();
        charger->pos[0] = position[0].get<double>();
        charger->pos[1] = position[1].get<double>();
        charger->pos[2] = position[1].get<double>();
	
        return charger;
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
