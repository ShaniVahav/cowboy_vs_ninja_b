//
// Created by shani on 19/05/2023.
//

#ifndef COWBOY_VS_NINJA_B_YOUNGNINJA_HPP
#define COWBOY_VS_NINJA_B_YOUNGNINJA_HPP

/// YoungNinja is with permanent parameters: health = 100 and speed = 14

#include "Ninja.hpp"

class YoungNinja : public Ninja{
public:
    YoungNinja(string name, Point location) : Ninja(name, location, 100, 14) {};
};


#endif //COWBOY_VS_NINJA_B_YOUNGNINJA_HPP
