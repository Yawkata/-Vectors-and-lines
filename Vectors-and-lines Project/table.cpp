#include "table.h"

// function to checks if the filed's sides ratio is 2:1
double Table::verify_simple_case(double a, double b)
{
    return a / b == 2;
}

// function to check if the given four points make rectangle with side ratio 2:1
double Table::verify_complex_case(Point A, Point B, Point C, Point D)
{
    return verify_simple_case(Vector(A, B).length(), Vector(D, A).length()) &&
           Line(A, B).is_orthogonal(Line(B, C)) &&
           Line(B, C).is_orthogonal(Line(C, D)) &&
           Line(C, D).is_orthogonal(Line(A, D));
}

// default constructor
Table::Table()
{
    this->A = Point(0, 0);
    this->B = Point(320, 0);
    this->C = Point(320, 160);
    this->D = Point(0, 160);
}

// constructor for simple case where sides of the table are perpendicular to the coordinate system
Table::Table(Point start, double a, double b)
{
    if (verify_simple_case(a, b) == 0)
        throw std::invalid_argument("Sides of the table should be in a 1:2 ratio.");

    this->A = start;
    this->B = Point(start.x + a, start.y);
    this->C = Point(start.x + a, start.y + b);
    this->D = Point(start.x, start.y + b);
}

// constructor for complex case where sides of the table are NOT perpendicular to the coordinate system
Table::Table(Point A, Point B, Point C, Point D)
{
    if (verify_complex_case(A, B, C, D) == 0)
        throw std::invalid_argument("Sides of the table should be in a 1:2 ratio and parallel to each other.");
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}

void Table::set_points(Point A, Point B, Point C, Point D)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}

// finds the area of the field given two vectors denoting two of its sides
double Table::get_area()
{
    Vector AB = Vector(this->A, this->B);
    Vector BC = Vector(this->B, this->C);

    return AB.length() * BC.length();
}

// function that shrinks the table by translating its sides by the diameter of the ball
Table Table::resize_table(double diameter)
{
    // getting the radius of the ball
    double radius = diameter / 2;

    // making the four lines forming the table
    Line AB = Line(this->A, this->B);
    Line BC = Line(this->B, this->C);
    Line CD = Line(this->C, this->D);
    Line DA = Line(this->D, this->A);

    // getting the ortogonal vectors of the two ortogonal sides (a and b)
    Vector direction_vector_AB = AB.orthogonal();
    Vector direction_vector_BC = BC.orthogonal();

    // making a vector ortogonal to the sides with magnitude of the radius of the ball;
    // then translating the four sides by this vector;
    // two of the lines must translate in the opposite direction, that's why their vectors are multiplied by negative radius
    AB = AB.translate_line_by_vector(this->A, direction_vector_AB.translation_vector(radius * -1));
    BC = BC.translate_line_by_vector(this->B, direction_vector_BC.translation_vector(radius * -1));
    CD = CD.translate_line_by_vector(this->C, direction_vector_AB.translation_vector(radius));
    DA = DA.translate_line_by_vector(this->D, direction_vector_BC.translation_vector(radius));

    // calculating the new four points formed by the translated lines
    Point A = AB.get_intersection_point(DA);
    Point B = AB.get_intersection_point(BC);
    Point C = BC.get_intersection_point(CD);
    Point D = CD.get_intersection_point(DA);

    Table resized_table;
    resized_table.set_points(A, B, C, D);

    return resized_table;
}
