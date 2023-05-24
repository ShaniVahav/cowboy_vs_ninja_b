//
// Created by shani on 19/05/2023.
//

#include "Team2.hpp"

void Team2::add(Character *fighter) {
    // check if this character is already in a team
    if(fighter->get_isFighter()){
        throw runtime_error("This Character is already in a team!");
    }
    fighter->set_isFighter(true);

    // if another fighter CANNOT be assigned
    if (this->_fightersTeam.size() >= this->_maxFighter){
        // the team has already reached to its maximum assignment
        throw runtime_error("Can not add another fighter to the team. The team is already full!");
    }

    /// for this team2 the order of the fighters is as usual
    this->_fightersTeam.push_back(fighter);
}