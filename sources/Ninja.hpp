#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string ninja_name, Point positionNin);
        void move(Character *enemy);
        void slash(Character *enemy);

    };
}

#endif // NINJA_HPP