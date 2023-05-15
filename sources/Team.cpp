#include <iostream>
#include <cmath>

#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *pLeader)
    {
        leader = pLeader;
    }

    Team::~Team()
    {
    }
    bool Team::isMember(Character *character)
    {
        return true;
    }
    void Team::add(Character *figther_to_add)
    {
    }
    void Team::attack(Team *enemy_team)
    {
    }
    int Team::stillAlive()
    {
        return 1;
    }
    void Team::print()
    {
    }
    Character *Team::getByOrder()
    {
        return NULL;
    }

}