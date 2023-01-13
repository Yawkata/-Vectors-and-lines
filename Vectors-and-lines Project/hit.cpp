#include "hit.h"

// chaeking if the power of the hit is in the range [1,10]
double Hit::validate_power(double power)
{
    if (power >= 1 && power <= 10)
    {
        return power;
    }
    throw std::invalid_argument("Power must be in range [1,10]");
}

Hit::Hit(double power, Point direction)
{
    this->power = validate_power(power);
    this->direction = direction;
}
