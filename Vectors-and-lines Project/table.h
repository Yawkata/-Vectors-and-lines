#ifndef TABLE_H
#define TABLE_H

#include "line.h"

class Table
{
public:
    Point A, B, C, D;

    // function to checks if the filed's sides ratio is 2:1
    static double verify_simple_case(double a, double b);

    // function to check if the given four points make rectangle with side ratio 2:1
    static double verify_complex_case(Point A, Point B, Point C, Point D);

    // default constructor
    Table();

    // constructor for simple case where sides of the table are perpendicular to the coordinate system
    Table(Point start, double a, double b);

    // constructor for complex case where sides of the table are NOT perpendicular to the coordinate system
    Table(Point A, Point B, Point C, Point D);

    void set_points(Point A, Point B, Point C, Point D);

    // finds the area of the field given two vectors denoting two of its sides
    double get_area();

    // function that shrinks the table by translating its sides by the diameter of the ball
    Table resize_table(double diameter);
};

#endif