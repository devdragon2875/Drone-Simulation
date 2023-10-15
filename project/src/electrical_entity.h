#ifndef ELECTRICAL_ENTITY_H_
#define ELECTRICAL_ENTITY_H_
/**
 * @file electrical_entity.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include "entity.h"



/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class that represents the Battery Life Decorator for entities. Adds a variable batterLife to energy and energyCapcity.
 *
 *
 */

class ElectricalEntity : public Entity{
public:
    /**
         * @brief Destructor. Removes the entity member variable.
         *
         * @return Nothing.
         */

    ~ElectricalEntity(){delete entity;}

    /**
         * @brief Constructor. Takes in an entity in which the decorator will add its batteryLife to the energyCapacity and energy. The default battery is 100.
         *
         * @return Nothing.
         */

    ElectricalEntity(Entity* entity);

    /**
         * @brief Constructor. Takes in an entity in which we will add the batteryCapacity to the energyCapacity and energy. The batteryCapcity will represent the batteryLife of the electrical entity.
         *
         * @return Nothing.
         */


    ElectricalEntity(Entity* entity, double batteryCapacity);

    /**
         * @brief Calls the entity's Update function.
         *
         * @return Nothing.
         */

    void Update(double dt);

    Entity* getEntity(){return entity;} //Getter for entity member variable
private:
    Entity* entity;//Entity in which we are creating thi decorator for
    double batteryCapacity;//The added battery capacity of the electrical entity
};


#endif

