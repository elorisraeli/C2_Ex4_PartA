#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

using namespace std;

namespace ariel
{
    class Team
    {
    private:
        vector<Character *> fighters;
        Character *leader;
        bool isMember(Character *character);

    public:
        Team(Character *pLeader);
        ~Team();
        void add(Character *figther_to_add);
        void attack(Team *enemy_team);
        int stillAlive();
        void print();
        virtual Character *getByOrder();

        void remove(Character *fighter_to_remove);
        Character *getLeader();
        size_t size();
    };
}

#endif // TEAM_HPP