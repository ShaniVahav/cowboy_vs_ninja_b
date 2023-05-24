//
// Created by shani on 19/05/2023.
//

#ifndef COWBOY_VS_NINJA_B_OLDNINJA_H
#define COWBOY_VS_NINJA_B_OLDNINJA_H

#include "Ninja.hpp"

/// OldNinja is with permanent parameters: health = 150 and speed = 8

class OldNinja : public Ninja{
public:
    OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {};
};

#endif //COWBOY_VS_NINJA_B_OLDNINJA_H
