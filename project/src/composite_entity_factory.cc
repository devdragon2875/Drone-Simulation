/**
 * @file composite_entity_factory.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "composite_entity_factory.h"
#include "entity.h"
#include "entity_factory.h"
#include <memory>
#include <iostream>

Entity* CompositeEntityFactory::CreateEntity(picojson::object& entityData,ICameraController& cameraController){
    //Lookup to see if we have a factories that exists for this entity, if we have one, create and return the entity.
    if(this->entityFactories.find(entityData["name"].get<std::string>())!=entityFactories.end()){
        Entity* entity=this->entityFactories[entityData["name"].get<std::string>()]->CreateEntity(entityData,cameraController);
        return entity;
    }
    else{ //No factory exists in our map for this entity.
        std::cout<<"Factory doesn't exist to create this entity."<<std::endl;
        std::cout<<"JSON string:"<<entityData["name"].get<std::string>()<<std::endl;
        return NULL;
    }
}

void CompositeEntityFactory::AddFactory(EntityFactory* factory){
    //Add the factory passed in.
    this->entityFactories[factory->getName()] = std::unique_ptr<EntityFactory>(factory);
}

std::string CompositeEntityFactory::checkFactory(std::string name){ // FOR TESTING OF ADDFACTORY ONLY
    if(this->entityFactories.find(name)!=entityFactories.end()){
        return this->entityFactories[name]->getName();
    }
    else{
        std::string returnmsg="Factory doesn't exist to create this entity.";
        return returnmsg;
    }
}

