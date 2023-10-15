#ifndef ROBOT_H_
#define ROBOT_H_

#include <string>
/**
 * @file robot.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple
 */ 

/*******************************************************************************
 * Includes
 ******************************************************************************/
class Robot : public Entity {
public:
    const std::string& GetName(){
        static std::string name("robot");
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