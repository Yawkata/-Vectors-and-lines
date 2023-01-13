#include "vector.h"

#include <math.h>

Vector::Vector()
{
    this->x = 0;
    this->y = 0;
}
Vector::Vector(double x, double y)
{
    this->x = x;
    this->y = y;
}
// constructs vector from 2 points
Vector::Vector(const Point p1, const Point p2)
{
    this->x = p2.x - p1.x;
    this->y = p2.y - p1.y;
}

// returns the sum of two vectors (which is also e vector)
Vector Vector::sum(const Vector &other) const
{
    return Vector(this->x + other.x, this->y + other.y);
}

// returns the product of a vector and a number (which is also e vector)
Vector Vector::times_num(double num) const
{
    return Vector(this->x * num, this->y * num);
}

// returns the unit vector of a given vector
Vector Vector::unit_vector()
{
    return this->times_num(1 / this->length());
}

// makes a traslation vector from its unit vector and a given magnitude
Vector Vector::translation_vector(double movement)
{
    return this->unit_vector().times_num(movement);
}

// returns a boolean value, answering the question whether the current
// vector and another ("other") are collinear
bool Vector::is_colinear(const Vector &other) const
{
    if (this->x * other.y - other.x * this->y == 0)
    {
        return true;
    }
    return false;
}

// returns the length of the current vector
double Vector::length() const
{
    return sqrt(this->x * this->x + this->y * this->y);
}

// returns the dot(scalar) product of the current vector and another
double Vector::dot_product(const Vector &other) const
{
    return this->x * other.x + this->y * other.y;
}

// finds the area of a triangle given two vectors denoting two of its sides
double Vector::area(const Vector v1, const Vector v2)
{
    double A = v1.length();
    double B = v2.length();
    double C = (v1.sum(v2.times_num(-1))).length();
    double p = (A + B + C) / 2;
    double S = sqrt(p * (p - A) * (p - B) * (p - C));

    return S;
}

