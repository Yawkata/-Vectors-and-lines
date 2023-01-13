#ifndef POINT_H
#define POINT_H

#include <iostream>

#define TOLERANCE 0.000001
using namespace std;

struct Point
{
    double x, y;

    Point();
    Point(double x, double y);
};

// this is for inputing a point
inline istream &operator>>(istream &in, Point &p)
{
    in >> p.x;
    in >> p.y;

    return in;
}

// this is for printing a point
inline ostream &operator<<(std::ostream &out, Point &p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

// function to determine if point C is between point A and point B (excluding points A and B) considering that they are on the same line  (A-------C---B);
bool chaeck_if_point_is_between_two_points(Point A, Point B, Point C);

// function to determine if point C is between point A and point B (including points A and B) considering that they are on the same line  (A-------C---B);
bool chaeck_if_point_is_between_two_corners(Point A, Point B, Point C);


#endif