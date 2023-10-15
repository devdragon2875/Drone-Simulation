#ifndef CHARGER_H_
#define CHARGER_H_

#include <string>

/**
 * @file charging_station.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple
 */ 

/*******************************************************************************
 * Includes
 ******************************************************************************/
class ChargingStation : public Entity {
public:
    const std::string& GetName(){
        static std::string name("recharge station");
        return name;}
    // Returns the position of the entity in space
    double* GetPosition(){
        double* a;
        
        return a;
    }
    int id;
    double pos[3];
};

#endif
