//
// Created by shani on 19/05/2023.
//

#ifndef COWBOY_VS_NINJA_B_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_B_SMARTTEAM_HPP

/// SmartTeam during an attack goes over the fighters in the following way:
/// First it goes over all the ninjas that are at most 1 meter away from the victim
/// (the goal is to eliminate the victim using as few fighters as possible),
/// After that the cowboys - in order for them to bring the final straw if the ninjas didn't bring.
/// And finally the distant ninjas who need to move forward -
/// so that they will always move towards an enemy that has not yet been eliminated.

#include "Team.hpp"

class SmartTeam : public Team{
public:
    SmartTeam(Character* chief) : Team(chief) {}

    Character* attack_victim(Team* enemy, Character* victim) override;
};


#endif //COWBOY_VS_NINJA_B_SMARTTEAM_HPP
