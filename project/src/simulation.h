#ifndef SIMULATION_H_
#define SIMULATION_H_
/**
 * @file Simulation.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_factory.h"
#include "entity.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A facade for all work done inside of the simulation that is communicated to the web app.
 * 
 *  
 */
class Simulation{

private:

public:
std::vector<Entity*> ents;
    /**
      * @brief Constructor for simulation object.
      * @return Nothing.
    */
Simulation(){};
/**
      * @brief Creates an enitity based on inputted JSON information
      * @return Nothing. Void function.
      */
void CreateEntity(picojson::object& entityData, ICameraController& cameraController) {
    // Creates an entity based on JSON data stored as an object.

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;
    CompositeEntityFactory fac;
    ents.push_back(fac.CreateEntity(entityData,cameraController));
}

/**
    * @brief This function updates the simulation based on the drone movement.
    * @return Nothing. Void function.
    */
void Update(double dt) {
    Entity* e = ents[0];
	e->Update(dt);
}
/**
    * @brief This function finishes the update by updating the JSON information.
    * @return Nothing. Void function.
    */
void FinishUpdate(picojson::object& returnValue) {
    ElectricalEntity* electrical_drone = dynamic_cast<ElectricalEntity*>(ents[0]);
    Drone* drone = dynamic_cast<Drone*>(electrical_drone->getEntity());
    // Below is an example of how to send the position and direction to the UI.  
    // In general you will want to loop through entities that have changed to update
    // their position and direction:
    picojson::object entity;
    entity["entityId"] = picojson::value((double)0);
    
    // Save the position as an array
    //cout << "POSITION: " << drone->getX() << ", " << drone->getY() << ", " << drone->getZ()<< "\n"; 
    picojson::array pos;
    pos.push_back(picojson::value(drone->getX()));
    pos.push_back(picojson::value(drone->getY()));
    pos.push_back(picojson::value(drone->getZ()));
    entity["pos"] = picojson::value(pos);

    // Save the direction as an array
    picojson::array dir;
    dir.push_back(picojson::value(drone->getXDir()));
    dir.push_back(picojson::value(drone->getYDir()));
    dir.push_back(picojson::value(drone->getZDir()));
    entity["dir"] = picojson::value(dir);
    //std::cout << "AFTER DYNAMIC CAST \n";

    // Send the compile picojson data to the UI in the returnValue variable
    returnValue["entity"+std::to_string(drone->getID())] = picojson::value(entity);
}

};

#endif