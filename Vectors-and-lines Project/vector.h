#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

class Vector
{
public:
    double x, y;

    Vector();
    Vector(double x, double y);

    // constructs vector from 2 points
    Vector(const Point p1, const Point p2);

    // returns the sum of two vectors (which is also e vector)
    Vector sum(const Vector &other) const;

    // returns the product of a vector and a number (which is also e vector)
    Vector times_num(double num) const;

    // returns the unit vector of a given vector
    Vector unit_vector();

    // makes a traslation vector from its unit vector and a given magnitude
    Vector translation_vector(double movement);

    // returns a boolean value, answering the question whether the current
    // vector and another ("other") are collinear
    bool is_colinear(const Vector &other) const;

    // returns the length of the current vector
    double length() const;

    // returns the dot(scalar) product of the current vector and another
    double dot_product(const Vector &other) const;

    // finds the area of a triangle given two vectors denoting two of its sides
    double area(const Vector v1, const Vector v2);
};

// this is for inputing a vector
inline std::ostream &operator<<(std::ostream &out, const Vector &v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

// this is for printing a vector
inline std::istream &operator>>(std::istream &in, Vector &v)
{
    in >> v.x;
    in >> v.y;
    return in;
}

#endif