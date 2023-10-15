/**
 * @file electrical_entity.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "electrical_entity.h"
ElectricalEntity::ElectricalEntity(Entity* entity) {
	this->entity = entity;
        this->entity->addEnergy(batteryCapacity);
}

ElectricalEntity::ElectricalEntity(Entity* entity, double batteryCapacity){
	this-> batteryCapacity = batteryCapacity;
	this->entity = entity;
	this->entity->addEnergy(batteryCapacity);
}

void ElectricalEntity::Update(double dt) {	
	entity->Update(dt);
	//entity.reduceEnergy(dt);
}


