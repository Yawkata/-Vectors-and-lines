#ifndef BALL_H
#define BALL_H

#include "hit.h"

class Ball
{
public:
    Point startPosition;
    Point currPosition;
    Point prevPosition;
    double diameter;

    // checks if the ball is in the borders of the field
    bool is_inTable(Table table);

    // default constructor
    Ball();

    Ball(Point startPosition, double diameter);

    void set_diameter(double new_diameter);

    void set_starting_position(Point new_starting_position);

    Line wall_of_bounce(Point corner_of_table1, Point corner_of_table2, int *valid_points_count, Line coalision_line);

    // function to get the position of the ball by a given hit
    void hit_the_ball(Hit hit, Table table);


};

#endif