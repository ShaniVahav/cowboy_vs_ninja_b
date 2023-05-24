//
// Created by shani on 16/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_CHARACTER_H
#define COWBOY_VS_NINJA_A_CHARACTER_H

#include <iostream>
#include "Point.hpp"
using namespace std;
namespace ariel{}


/// The class represents an character in the game

class Character {
public:
    Character(string name, Point location, int health) : _name(name), _location(location), _health(health){}

    virtual ~Character() = default;

    // if character '_health' > 0 so he is alive
    bool isAlive() const;

    // get pointer to another character and return the distance from this character
    double distance(const Character* other) const;

    // get the number of hit in this character
    // reduce the num of hits from 'health' attribute
    void hit (int num);

    // print the: N - for ninja, C - cowboy, {name, number of hits, location} of the character
    // if the character is not alive - number of hits will not be printed and the name will be in parentheses
    virtual string print() const;

    virtual void attack(Character* enemy) = 0;  // pure virtual function

    virtual string type() const = 0; // "Cowboy" or "Ninja"

    string getName() const { return this->_name; }

    Point getLocation() const {return this->_location; }

    bool get_isChief() const {return this->_isChief;}

    void set_isChief(bool flag){ this->_isChief = flag;}

    bool get_isFighter() const {return this->_isFighter;}

    void set_isFighter(bool flag){ this->_isFighter = flag;}

public: // protected:
    string _name;
    Point _location;
    int _health;  // number of hits that the character can get and stay alive
    bool _isChief = false;
    bool _isFighter = false;
};


#endif //COWBOY_VS_NINJA_A_CHARACTER_H
