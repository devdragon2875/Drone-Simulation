/**
 * @file drone_factory.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "drone_factory.h"

DroneFactory::DroneFactory(){
    this->name="drone";
}

Entity* DroneFactory::CreateEntity(picojson::object& entityData,ICameraController& cameraController){
          
        Drone* drone = new Drone();
        drone->setID(entityData["entityId"].get<double>());
        drone->setSpeed(entityData["speed"].get<double>());

        //Get the position as an array from the JSON
        picojson::array position = entityData["position"].get<picojson::array>();

        //Get the direction as an array from the JSON
        picojson::array dir = entityData["direction"].get<picojson::array>();
        
        drone->setX(position[0].get<double>());
        drone->setY(position[1].get<double>());
        drone->setZ(position[2].get<double>());

        //Get the direction as an array from the JSON
        drone->setXDir(dir[0].get<double>());
        drone->setYDir(dir[1].get<double>());
        drone->setZDir(dir[2].get<double>());

        //Create cameras for the drone.
        picojson::array cameras = entityData["cameras"].get<picojson::array>();
        for (int i = 0; i < cameras.size(); i++) {
            Camera* camera = new Camera(cameras[i].get<double>(), &cameraController);
            drone->cameras.push_back(camera);
        }

	//Decorating the drone in an electrical entity with a battery capacity
	ElectricalEntity* electric_drone = new ElectricalEntity(drone, 100);
        return electric_drone;
}

std::string DroneFactory::getName(){
    return this->name;
}
