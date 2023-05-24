//
// Created by shani on 17/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_COWBOY_H
#define COWBOY_VS_NINJA_A_COWBOY_H

#include "Character.hpp"

class Cowboy : public Character{
public:
    // every Cowboy creates with 110 health and 6 num of bullets
    Cowboy(string name, Point location) : Character(name, location, 110) {};

    // If this cowboy is not dead and he has bullets so this cowboy reduce 10 health point from the enemy
    // the cowboy loos 1 bullets
    // otherwise - nothing happen to the enemy
    void shoot(Character* enemy);

    // attack call shoot - but reload the gun if is empty (while team attack)
    void attack(Character* enemy) override;

    // return if this Cowboy left some bullets
    bool hasboolets() const;

    // reload the gun with 6 bullets
    void reload();

    int getNumOfBullets() const {return _num_of_bullets;}

    string type() const override { return "Cowboy";}

private:
    int _num_of_bullets = 6;
};

#endif