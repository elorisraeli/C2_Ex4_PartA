#include <iostream>
#include <cmath>

#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(string ninja_name, Point positionNin) : Character(ninja_name, positionNin)
    {
    }
    void Ninja::move(Character *enemy)
    {
    }
    void Ninja::slash(Character *enemy)
    {
    }

    int Ninja::getSpeed() 
    {
        return 0;
    }

}