#include <iostream>
#include <cmath>

#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(string cow_name, Point positionCo) : Character(cow_name, positionCo)
    {
    }
    void Cowboy::shoot(Character *enemy)
    {
    }
    bool Cowboy::hasboolets()
    {
        return true;
    }
    void Cowboy::reload()
    {
    }

}