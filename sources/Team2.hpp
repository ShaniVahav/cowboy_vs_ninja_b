//
// Created by shani on 19/05/2023.
//

#ifndef COWBOY_VS_NINJA_B_TEAM2_HPP
#define COWBOY_VS_NINJA_B_TEAM2_HPP

#include "Team.hpp"

 /// in Team2 the iteration on the team iterate first on cowboys and then on ninjas.

class Team2 : public Team{

public:
    Team2(Character *chief) : Team(chief) {};

    void add(Character* fighter) override;
};


#endif //COWBOY_VS_NINJA_B_TEAM2_HPP
