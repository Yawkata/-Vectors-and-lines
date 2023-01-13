#ifndef LINE_H
#define LINE_H

#include "vector.h"

class Line
{

public:
    double A, B, C;

    Line();

    Line(double A, double B, double C);

    // constructs a line given a point and a vector
    Line(const Point p, const Vector &v);

    // constructs a line given two points
    Line(const Point p1, const Point p2);

    // checks if two lines a parallel to eachother
    bool are_parallel(const Line &other) const;

    // checks if two lines are orthogonal (perpendicular)
    bool is_orthogonal(const Line &other) const;

    // returns the vector that is colinear to the line
    Vector colinear() const;

    // returns the vector that is orthogonal to the line
    Vector orthogonal() const;

    // returns a line, passing through the point p, that is parallel to the line
    Line parallel(const Point p) const;

    // returns a line, passing through the point p, that is orthogonal to the line
    Line orthogonal(const Point p) const;

    // returns a line translated by a given vector and initial point of the vector
    Line translate_line_by_vector(Point initial_point, Vector translation_vector);

    // returns the point where two lines intersect
    Point get_intersection_point(Line line2);

    // function to get the reflection of a given point by given line
    Point get_symmetrical_point(Point point);
};

// this is for inputing a line
inline std::ostream &operator<<(std::ostream &out, const Line &l)
{
    out << l.A << "x + " << l.B << "y + " << l.C << " = 0 ";
    return out;
}

// this is for printing a line
inline std::istream &operator>>(std::istream &in, Line &l)
{
    in >> l.A;
    in >> l.B;
    in >> l.C;
    return in;
}

#endif