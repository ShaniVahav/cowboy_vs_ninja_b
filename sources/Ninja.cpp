//
// Created by shani on 17/05/2023.
//

#include "Ninja.hpp"

void Ninja::move(const Character *enemy) {
    // get ninja closer to the enemy
    Point new_location = Point::moveTowards(this->_location, enemy->getLocation(), this->_speed);
    this->_location = new_location;
}

void Ninja::slash(Character *enemy) const {
    // if the enemy is already dead
    if(!enemy->isAlive()){
        throw runtime_error("Cannot attack a DEAD enemy");
    }

    // if the enemy is the attacker himself
    if(this == enemy){
        throw runtime_error("Ninja cannot attack himself");
    }

    // if the attacker is dead
    if(!this->isAlive()){
        throw runtime_error("This fighter is dead and cannot attack!");
    }

    // if the ninja is alive
    if(this->_health > 0){
        // if the ninja less than 1 meter away from the enemy
        double distFromEnemy = this->distance(enemy);
        if(distFromEnemy < 1){
            enemy->hit(40);
        }
    }
}

void Ninja::attack(Character *enemy) {
    double distFromEnemy = this->distance(enemy);
    if(this->isAlive()) {
        if (distFromEnemy < 1) {
            // the ninja is alive and close enough to the enemy
            this->slash(enemy);
        } else {
            this->move(enemy);  // get closer to enemy
        }
    }
}
