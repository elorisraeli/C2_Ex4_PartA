#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include <iostream>
#include <vector>
#include "Team.hpp"

using namespace std;

namespace ariel
{
    class SmartTeam : public Team
    {
    private:


    public:
        SmartTeam(Character* pLeaderT2);
        ~SmartTeam();
        Character* getByOrder();

    };
}

#endif // SMART_TEAM_HPP