//
// Created by shani on 17/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_NINJA_H
#define COWBOY_VS_NINJA_A_NINJA_H

#include "Character.hpp"

class Ninja : public Character{
public:
    Ninja(string name, Point location, int health, int speed) :
    Character(name, location, health), _speed(speed){};

    // The ninja get closer to the enemy accordingly to his speed
    void move(const Character* enemy);

    // if the ninja is alive and the enemy is less than 1m' from him - so the ninja reduce 40 health from the enemy
    // otherwise - nothing will happen to the enemy
    void slash(Character* enemy) const;

    // attack call slash - but move the nonja closer if the enemy not close enough (while team attack)
    void attack(Character* enemy) override;

    string type() const override { return "Ninja";}


protected:
    int _speed;

};

#endif //COWBOY_VS_NINJA_A_NINJA_H
