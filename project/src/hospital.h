#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include <string>

/**
 * @file hospital.h
 *
 * @copyright 2021 3081W, Group 21 All rights reserved. Author: Robert Maple
 */ 

/*******************************************************************************
 * Includes
 ******************************************************************************/
class Hospital : public Entity {
public:
    const std::string& GetName(){
        static std::string name("hospital");
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