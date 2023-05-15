#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point positionP;
        int Hit_Points;
        string name;

    public:
        Character(string ch_name, Point position);
        Character(string ch_name, Point position, int HPoints);
        bool isAlive();
        double distance(Character *other);
        void hit(int damage);
        string getName();
        Point getLocation();
        virtual string print();

        int getHitPoints();
        void moveTowards(Point destination, double distance);
    };
}

#endif // CHARACTER_HPP