//
// Created by shani on 17/05/2023.
//

#include <vector>
#include <limits>  // for max double number
#include <sstream>
#include "Team.hpp"
using namespace std;

Team::Team(Character *chief) : _chief(chief) {
    // check is the character is already a chief
    if(chief->get_isChief()){
        throw runtime_error("A Character Cannot be a chief of two different team.");
    }
    this->_fightersTeam.push_back(chief);
    chief->set_isChief(true);
    chief->set_isFighter(true);
};

Team::~Team() {
    for (Character* fighter : this->_fightersTeam){
        delete(fighter);
    }
}


void Team::add(Character *fighter) {
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
    /// for this team we want the cowboys be first in order, and then the ninjas
    if (fighter->type() == "Ninja"){
        // can be pushed back
        this->_fightersTeam.push_back(fighter);
    }
    else{
        // it's cowboy
        // find the last cowboy index
        int index = 0;
        for (Character* fighter_ : this->_fightersTeam) {
            if (fighter_->type() == "Ninja"){
                break;
            }
            index++;
        }
        // insert the cowboy in the right place
        this->_fightersTeam.insert(this->_fightersTeam.begin() + index, fighter);
    }
}

void Team::attack(Team *enemy) {
    // check validation
    if(enemy == nullptr){
        throw invalid_argument("nullptr is an invalid argument!");
    }

    if (this->stillAlive() == 0 || enemy->stillAlive() == 0){
        throw runtime_error("Cannot attack a dead team.");
    }

    /// If the chief is dead - replaced him
    if (!this->_chief->isAlive()){
        // chief is dead - choose another one by distance from the dead chief
        bool chief_isReplaced = this->changeChief();
        if (!chief_isReplaced){
            // The chief was not replaced - this team was eliminated. End of attack.
            return;
        }
    }

    /// Find the victim from the enemy's team and attack him
    Character* victim = this->findVictim_at(enemy);

    if(this->attack_victim(enemy, victim) == nullptr){
        // the enemy team is dead
        return;
    }

}


Character* Team::attack_victim(Team* enemy, Character* victim){
    for(Character* fighter : this->_fightersTeam){
        if (fighter->isAlive()){
            fighter->attack(victim);
        }
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
    return victim;
}


int Team::stillAlive() const {
    int numOfAlive = 0;
    for (const Character* fighter : this->_fightersTeam) {
        // check if the fighter is alive
        if(fighter->isAlive())
            numOfAlive++;
    }

    return numOfAlive;
}

string Team::print() const {
    ostringstream ss;
    for(Character* team_mate : this->_fightersTeam){
        ss << team_mate->print() << endl;
    }
    return ss.str();
}

bool Team::changeChief() {
    /// The new chief is the closet teammate to the dead chief that alive
    Character* newChief = this->_chief;  // initialize

    double min_distance = numeric_limits<double>::max();
    bool chief_is_change = false;

    double distance_fighterToChief;
    for(Character* fighter : this->_fightersTeam){
        if (fighter->isAlive()){  // check if the optional chief is alive
            distance_fighterToChief = fighter->distance(this->_chief);
            if(distance_fighterToChief < min_distance){
                // this fighter for now is the closet teammate that alive
                min_distance = distance_fighterToChief;
                newChief = fighter;  // change the chief;
                chief_is_change = true;
            }
        }
    }

    this->_chief = newChief;  // if 'chief_is_change' is false, then 'newChief' is still the oldChief
    return chief_is_change;
}

Character* Team::findVictim_at(const Team *enemy) const{
  /// The victim is the living enemy team member
  /// who standing closest to the chief of the attacking (this) team.

    Character* victim;
    double min_distance = numeric_limits<double>::max();

    double distance_victimToChief;
    for(Character* enemy_member : enemy->_fightersTeam){
        if (!enemy_member->isAlive()){
            // if the enemy_member is dead so continue to the next one
            continue;
        }

        distance_victimToChief = enemy_member->distance(this->_chief);

        if (distance_victimToChief < min_distance){
            // this enemy_member for now is the victim
            victim = enemy_member;
            min_distance = distance_victimToChief;
        }
    }
    return victim;
}