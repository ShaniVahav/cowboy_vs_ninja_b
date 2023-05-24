//
// Created by shani on 17/05/2023.
//

#include "Cowboy.hpp"

void Cowboy::shoot(Character *enemy) {
    // if the enemy is already dead
    if(!enemy->isAlive()){
        throw runtime_error("Cannot attack a DEAD enemy");
    }

    // if the enemy is the attacker himself
    if(this == enemy){
        throw runtime_error("Cowboy cannot shoot himself");
    }

    // if the attacker is dead
    if(!this->isAlive()){
        throw runtime_error("This fighter is dead and cannot attack!");
    }

    if(this->_num_of_bullets > 0){  // check if the cowboy has bullets
        // cowboy shooting is reducing 10 from enemy's health
        enemy->hit(10);
        this->_num_of_bullets--;
    }
}

void Cowboy::attack(Character* enemy) {
    if(this->hasboolets()) {
        this->shoot(enemy);
    }
    else{
        this->reload();
    }
}

bool Cowboy::hasboolets() const{
    return this->_num_of_bullets > 0;
}


void Cowboy::reload() {
    if(!this->isAlive()){
        throw runtime_error("Dead cowboy cannot reload!");
    }

    this->_num_of_bullets = 6;
}

