#include "line.h"

Line::Line(){
    this->A = 0;
    this->B = 0;
    this->C = 0;
}

Line::Line(double A, double B, double C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}
// constructs a line given a point and a vector
Line::Line(const Point p, const Vector &v)
{
    this->A = v.y;
    this->B = -v.x;
    this->C = -(A * p.x + B * p.y);
}

// constructs a line given two points
Line::Line(const Point p1, const Point p2)
{

    this->A = (p2.y - p1.y);
    this->B = (p1.x - p2.x);
    this->C = -(this->A * (p1.x) + this->B * (p1.y));
}

// checks if two lines a parallel to eachother
bool Line::are_parallel(const Line &other) const
{
    return (this->A * other.B == this->B * other.A);
}

// checks if two lines are orthogonal (perpendicular)
bool Line::is_orthogonal(const Line &other) const
{
    return (this->A * other.A) == -(this->B * other.B);
}

// returns the vector that is colinear to the line
Vector Line::colinear() const
{
    return Vector(-(this->B), this->A);
}

// returns the vector that is orthogonal to the line
Vector Line::orthogonal() const
{
    return Vector(this->A, this->B);
}

// returns a line, passing through the point p, that is parallel to the line
Line Line::parallel(const Point p) const
{
    return Line(p, this->colinear());
}

// returns a line, passing through the point p, that is orthogonal to the line
Line Line::orthogonal(const Point p) const
{
    return Line(p, this->orthogonal());
}

// returns a line translated by a given vector and initial point of the vector
Line Line::translate_line_by_vector(Point initial_point, Vector translation_vector)
{
    return this->parallel(Point(initial_point.x + translation_vector.x, initial_point.y + translation_vector.y));
}

// returns the point where two lines intersect
Point Line::get_intersection_point(Line line2)
{
    double x = (line2.C * this->B - this->C * line2.B) / (this->A * line2.B - line2.A * this->B);
    double y = (line2.A * this->C - this->A * line2.C) / (this->A * line2.B - line2.A * this->B);

    return Point(x, y);
}

// function to get the reflection of a given point by given line
Point Line::get_symmetrical_point(Point point)
{
    double x = (this->B * this->B * point.x - 2 * this->A * this->B * point.y - 2 * this->A * this->C - this->A * this->A * point.x) /
               (this->A * this->A + this->B * this->B);

    double y = (this->A * this->A * point.y - 2 * this->A * this->B * point.x - 2 * this->B * this->C - this->B * this->B * point.y) /
               (this->A * this->A + this->B * this->B);

    return Point(x, y);
}