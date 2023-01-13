#include "point.h"

using namespace std;

Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

// function to determine if point C is between point A and point B (EXCLUDING points A and B), considering that they are on the same line  (A-------C---B);
bool chaeck_if_point_is_between_two_points(Point A, Point B, Point C)
{
    // this if is for case where the hit is parallel to the sides of the table
    if (A.x == B.x || A.y == B.y)
    {
        if (C.y == A.y && C.x > min(A.x, B.x) + TOLERANCE && C.x < max(A.x, B.x) + TOLERANCE)
            return true;

        if (C.x == A.x && C.y > min(A.y, B.y) + TOLERANCE && C.y < max(A.y, B.y) + TOLERANCE)
            return true;
    }

    if (C.x > min(A.x, B.x) + TOLERANCE && C.x < max(A.x, B.x) + TOLERANCE && C.y > min(A.y, B.y) + TOLERANCE && C.y < max(A.y, B.y) + TOLERANCE)
    {
        return true;
    }

    return false;
}
// function to determine if point C is between point A and point B (INCLUDING points A and B), considering that they are on the same line  (A-------C---B);
bool chaeck_if_point_is_between_two_corners(Point A, Point B, Point C)
{
    // this if is for case where the hit is parallel to the sides of the table
    if (A.x == B.x || A.y == B.y)
    {
        if (C.y == A.y && C.x > min(A.x, B.x) + TOLERANCE && C.x < max(A.x, B.x) + TOLERANCE)
            return true;

        if (C.x == A.x && C.y > min(A.y, B.y) + TOLERANCE && C.y < max(A.y, B.y) + TOLERANCE)
        {

            return true;
        }
    }

    if (C.x >= min(A.x, B.x) && C.x <= max(A.x, B.x) && C.y >= min(A.y, B.y) && C.y <= max(A.y, B.y))
    {
        return true;
    }

    return false;
}