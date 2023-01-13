#include "ball.h"

// checks if the ball is in the borders of the field
bool Ball::is_inTable(Table table)
{
    Vector AP = Vector(table.A, this->currPosition);
    Vector BP = Vector(table.B, this->currPosition);
    Vector CP = Vector(table.C, this->currPosition);
    Vector DP = Vector(table.D, this->currPosition);

    double S_APB = AP.area(AP, BP);
    double S_BPC = BP.area(BP, CP);
    double S_CPD = CP.area(CP, DP);
    double S_DPA = DP.area(DP, AP);

    double S_ABCD = table.get_area();

    return S_APB + S_BPC + S_CPD + S_DPA <= S_ABCD + TOLERANCE;
}

// default constructor
Ball::Ball()
{
    this->startPosition = Point(280, 70);
    this->currPosition = startPosition;
    this->prevPosition = startPosition;
    this->diameter = 0;
}

Ball::Ball(Point startPosition, double diameter)
{
    this->startPosition = startPosition;
    this->currPosition = startPosition;
    this->prevPosition = startPosition;
    this->diameter = diameter;
}

void Ball::set_diameter(double new_diameter)
{
    this->diameter = new_diameter;
}

void Ball::set_starting_position(Point new_starting_position)
{
    this->startPosition = new_starting_position;
    this->currPosition = this->startPosition;
    this->prevPosition = this->currPosition;
}

Line Ball::wall_of_bounce(Point corner_of_table1, Point corner_of_table2, int *valid_points_count, Line coalision_line)
{
    //  Making the line representing the side formed by thr two given corners
    Line side_of_table = Line(corner_of_table1, corner_of_table2);

    // making the direction line formed by the previous and the current position of the ball
    Line direction_line = Line(this->prevPosition, this->currPosition);

    // getting all the coalision point between the direction line and the table side
    Point intersection_with_side = side_of_table.get_intersection_point(direction_line);

    // checking if the intersection point is lying on the side of the table (between the two corners)
    bool between_side = chaeck_if_point_is_between_two_corners(corner_of_table1, corner_of_table2, intersection_with_side);

    // checking if the intersection point is lying on the direction line (between the previous and the current position)
    bool between_prev_and_curr = chaeck_if_point_is_between_two_points(this->prevPosition, this->currPosition, intersection_with_side);

    // cheking if the point is lying on the sides of the table and is at the same time between the previous and the current position of the ball
    // if both are true that means the ball hit a wall
    if (between_side == true && between_prev_and_curr == true)
    {
        // setting current and previous position of the ball, setting the coalision line and incrementing the valid points count
        this->prevPosition = this->currPosition;
        this->currPosition = intersection_with_side;
        coalision_line = side_of_table;
        (*valid_points_count)++;
    }

    return coalision_line;
}

// function to get the position of the ball after a given hit
void Ball::hit_the_ball(Hit hit, Table table)
{

    // the vector which determines the direction of the hit
    Vector direction_vector = Vector(this->currPosition, hit.direction);

    // calculating the magnitude of the vector by the given power and by that determining the coordinates of the destination
    this->currPosition.x = this->currPosition.x + direction_vector.times_num(hit.power).x;
    this->currPosition.y = this->currPosition.y + direction_vector.times_num(hit.power).y;

    // cycle that makes the ball bounce of the walls while its destination is out of the table
    while (this->is_inTable(table) == false)
    {
        // wich wall has the ball bounced off
        Line coalision_line;

        // how many points are lying on the sides of the table and at the same time between the current position of the ball and the destination
        int valid_points_count = 0;

        // checking if the direction line is crossing any of the table's sides
        coalision_line = wall_of_bounce(table.A, table.B, &valid_points_count, coalision_line);
        coalision_line = wall_of_bounce(table.B, table.C, &valid_points_count, coalision_line);
        coalision_line = wall_of_bounce(table.C, table.D, &valid_points_count, coalision_line);
        coalision_line = wall_of_bounce(table.D, table.A, &valid_points_count, coalision_line);

        // if the ball hit two walls at the sime time that means it got into on of the corners of the table
        if (valid_points_count == 2)
        {
            this->prevPosition = this->currPosition;
            this->currPosition = startPosition;

            cout << "\nBALL GOT INTO CORNER" << endl;
            break;
        }

        // just in case
        if (valid_points_count == 0)
        {
            cout << "\nERROR!" << endl;
            cout << "There weren't any intersection points between the sides of the field and the direction line of the hit!" << endl;
            exit(1);
        }

        cout << "\nThe ball bounced into the wall at: " << this->currPosition << endl
             << endl;

        // calculating where the ball should go after a bounce
        Point symmetrical_point = coalision_line.get_symmetrical_point(this->prevPosition);

        this->prevPosition = this->currPosition;
        this->currPosition = symmetrical_point;
    }
    this->prevPosition = this->currPosition;

    cout << "\nBall has been succesfully hit!" << endl
         << "\nBALL CURRENT POSITION: " << this->currPosition << endl;
}
