/**
 * @file Entity.cc
 *
 * @copyright 2021 3081W, Author: Robert Maple, Group 21 All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity.h"

const std::string& Entity::GetName() {
    static std::string name("Entity");
    return name;
}

