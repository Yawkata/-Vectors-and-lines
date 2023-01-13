#ifndef HIT_H
#define HIT_H

#include "table.h"

class Hit
{
public:
    double power;
    Point direction;

    // chaeking if the power of the hit is in the range [1,10]
    static double validate_power(double power);

    Hit(double power, Point direction);
};

#endif