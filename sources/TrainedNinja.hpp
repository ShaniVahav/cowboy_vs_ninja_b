//
// Created by shani on 19/05/2023.
//

#ifndef COWBOY_VS_NINJA_B_TRAINEDNINJA_HPP
#define COWBOY_VS_NINJA_B_TRAINEDNINJA_HPP

#include "Ninja.hpp"

/// TrainedNinja is with permanent parameters: health = 120 and speed = 12

class TrainedNinja : public Ninja{
public:
    TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {};
};

#endif //COWBOY_VS_NINJA_B_TRAINEDNINJA_HPP
