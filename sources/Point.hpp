#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace ariel
{
    class Point
    {
    private:
        double x_axis;
        double y_axis;

    public:
        Point(double x_value, double y_value);

        double distance(Point point);

        void print();

        double moveTowards(Point source, Point destination, double distance);

    };
}

#endif // POINT_HPP