#include <iostream>
#include <cmath>

#include "Character.hpp"
using namespace std;

namespace ariel
{
    Character::Character(string ch_name, Point position) : name(ch_name), positionP(position)
    {
    }    
    Character::Character(string ch_name, Point position, int HPoints) : name(ch_name), positionP(position), Hit_Points(HPoints)
    {
    }

    bool Character::isAlive()
    {
        return true;
    }
    double Character::distance(Character *other)
    {
        return 0.0;
    }
    void Character::hit(int damage)
    {
    }
    string Character::getName()
    {
        return "";
    }
    Point Character::getLocation()
    {
        return Point(0.0, 0.0);
    }
    void Character::print()
    {
    }

}