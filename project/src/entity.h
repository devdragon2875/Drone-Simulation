#ifndef ENTITY_H_
#define ENTITY_H_
/**
 * @file entity.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Devansh Mishra
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "Point.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Entity is the base class for any simulation object. Abstract.
 * 
 *  
 */

class Entity {
public:
    /**
      * @brief Virtual Destructor.
      *
      * @return Nothing. 
      */
    virtual ~Entity() {}
    // Returns the name of the entity
    void setPos(double a, double b, double c){pos->x = a; pos->y = b; pos->z = c;} 
    void setX(double x) {pos->x = x;}
    void setY(double y) {pos->y = y;}
    void setZ(double z) {pos->z = z;}
    /**
      * @brief Function to return the name of the entity.
      *
      * @return String. Name of the factory.
      */
    virtual const std::string& GetName();

    /**
      * @brief This is the Update function called multiple times per second. Represents the change in the entity.
      *
      * @return Nothing.
      */
    virtual void Update(double dt) {}
    /**
      * @brief Adds to the energy and energyCapacity by a variable double "energyAdd"
      *
      * @return Nothing.
      */
    void addEnergy(double energyAdd){energyCapacity += energyAdd; energy += energyAdd;}
    /**
      * @brief Reduces just the energy by a variable double amount "energyReduce"
      *
      * @return Nothing.
      */
    void reduceEnergy(double energyReduce){energy -= energyReduce;}
    double getEnergy(){return energy;}
    double getEnergyCapacity(){return energyCapacity;}
protected:
    double energyCapacity;//represents the max amount of energy
    double energy;//represents the current energy
    Point* pos;
};


#endif
