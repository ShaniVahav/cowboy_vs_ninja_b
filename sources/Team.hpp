//
// Created by shani on 17/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_H
#define COWBOY_VS_NINJA_A_TEAM_H

#include <vector>
#include <iostream>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;

class Team {
public:
    explicit Team(Character *chief);

    ~Team();

    // add the fighter into the team
    virtual void add(Character *fighter);

    // if this chief is not alive so peak another one which closets to the dead chief's location
    // the fighter that will be attacked by all this, is the one on the enemy team that stands closest to this chief.
    // if the victim is dead so a new victim will be chosen.
    void attack(Team *enemy);

    virtual Character* attack_victim(Team* enemy, Character* victim);

    // number of fighters that still alive
    int stillAlive() const;

    // print the details on each member team
    string print() const;

    bool changeChief();  // return true if the replacement was successful. otherwise - false.

    Character* findVictim_at(const Team* enemy) const;

    Character *getChief() const { return this->_chief; }

    vector<Character *> getFighters_vec() const { return this->_fightersTeam; }


protected:
    const int _maxFighter = 10;
    vector<Character *> _fightersTeam;
    Character *_chief;

};
#endif //COWBOY_VS_NINJA_A_TEAM_H
