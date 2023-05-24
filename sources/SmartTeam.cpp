//
// Created by shani on 19/05/2023.
//

#include "SmartTeam.hpp"

Character *SmartTeam::attack_victim(Team *enemy, Character *victim) {
    // create 3 vectors:
    // 1. ninjas < 1m
    // 2. cowboys
    // 3. ninjas > 1m
    vector<Character*> ninjasClose;
    vector<Character*> cowboys;
    vector<Character*> ninjasFar;

    for(Character* attacker : this->_fightersTeam) {
        // insert to a vector just the lives
        if (attacker->isAlive()) {
            if (attacker->type() == "Ninja") {
                double distance = attacker->distance(victim);
                if (distance < 1.0) {
                    ninjasClose.push_back(attacker);
                } else {
                    ninjasFar.push_back(attacker);
                }
            } else if (attacker->type() == "Cowboy") {
                cowboys.push_back(attacker);
            }
        }
    }

    for (Character* ninja : ninjasClose) {
        ninja->attack(victim);

        if (!victim->isAlive()){
            // victim is dead
            // find another victim
            victim = this->findVictim_at(enemy);
            if (victim == nullptr){
                // the enemy team is dead
                return nullptr;
            }
        }
    }

    for (Character* cowboy : cowboys){
        cowboy->attack(victim);

        if (!victim->isAlive()){
            victim = this->findVictim_at(enemy);
            if (victim == nullptr){
                return nullptr;
            }
        }
    }

    for (Character* ninja : ninjasFar){
        ninja->attack(victim);

        if (!victim->isAlive()){
            victim = this->findVictim_at(enemy);
            if (victim == nullptr){
                return nullptr;
            }
        }
    }

    return victim;
}