//
// Created by shani on 17/05/2023.
//

#include <cmath>
#include <iostream>
#include <sstream>
#include "Character.hpp"
using namespace std;

bool Character::isAlive() const{
    return (this->_health > 0);
}

void Character::hit(const int num) {
    // check validation
    if(num < 0){
        throw invalid_argument("hit must be non-negative number!");
    }

    this->_health = this->_health-num;
}

double Character::distance(const Character *other) const{
    return this->_location.distance(other->_location);
}

string Character::print() const {
    std::ostringstream ss;
    if (this->type() == "Cowboy"){
        ss << "C_";
    }
    else{
        ss << "N_";
    }
    if (this->isAlive()){
    ss << "Name: " << this->_name << endl;
    ss << "Health: " << this->_health << endl;
    }
    else{
        ss << "(Name: " << this->_name << ")" << endl;
    }
    ss << "Current location: " << this->_location.print() << endl;

    return ss.str();
}