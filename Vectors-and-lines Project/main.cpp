#include <iostream>

#include "ball.h"

using namespace std;

void menu();

void table_methodslist();
Table table_simple_case_constructor();
Table table_complex_case_constructor();

void ball_methods_list();
void set_ball_starting_position(Ball &ball);
void set_ball_diameter(Ball &ball);

Hit hit_constructor();

void show_results(Table table, Ball ball);

int main()
{
    // The examples from the homework. Uncomment for faster testing.
    //  simple cases
    //  EX.1
    // Table table = Table(Point(0, 0), 320, 160);
    // Ball ball = Ball(Point(280, 70), 0);
    //  Hit hit = Hit(1, Point(-350, 70));

    // EX.2  //remove tolerance and '=' from check_between_two_points
    // Table table = Table(Point(0, 0), 320, 160);
    // Ball ball = Ball(Point(300, 60), 0);
    // Hit hit = Hit(3, Point(250, 30));

    // EX.3  //remove tolerance and '=' from check_between_two_points
    // Table table = Table(Point(0, 0), 320, 160);
    // Ball ball = Ball(Point(300, 60), 10);
    // Hit hit = Hit(3, Point(250, 30));

    // EX.4  //remove tolerance and '=' from check_between_two_points
    // Table table = Table(Point(0, 0), 320, 160);
    // Ball ball = Ball(Point(230, 50), 10);
    // Hit hit = Hit(2, Point(200, 20));

    // complex cases
    // EX.4
    // Table table = Table(Point(20, 10), Point(120, 110), Point(70, 160), Point(-30, 60));
    // Ball ball = Ball(Point(60, 80), 14.14213562373095);
    // Hit hit = Hit(2, Point(50, 50));

    // EX.5
    // Table table = Table(Point(60, -80), Point(220, 40), Point(160, 120), Point(0, 0));
    // Hit hit = Hit(1, Point(12, -316));
    // Ball ball = Ball(Point(90, -10), 20);

    // EX.5
    // Table table = Table(Point(60, -80), Point(220, 40), Point(160, 120), Point(0, 0));
    // Hit hit = Hit(1, Point(65, -45));
    // Hit hit2 = Hit(1, Point(40, -220));
    // Ball ball = Ball(Point(90, -10), 20);
    // ball.hit_the_ball(hit2, table);

    // EX.6
    // Table table = Table(Point(60, -80), Point(220, 40), Point(160, 120), Point(0, 0));
    // Hit hit = Hit(1, Point(39.76, -47.68));
    // Ball ball = Ball(Point(90, -10), 20);

    // THE ACTION
    // table.resize_table(ball.diameter);
    // cout << "A: " << table.A << "B: " << table.B << "C: " << table.C << "D: " << table.D << endl;
    // cout << ball.is_inTable(table) << endl;
    // ball.hit_the_ball(hit, table);

    char object, method;
    Table table;
    Ball ball;

    Table resized_tale = table.resize_table(ball.diameter);

    while (true)
    {
        menu();
        cout << "Enter: ";
        cin >> object;
        cout << endl
             << endl;
        if (object == 't')
        {
            table_methodslist();
            cin >> method;
            switch (method)
            {
            case '1':
                table = table_simple_case_constructor();
                break;
            case '2':
                table = table_complex_case_constructor();
                break;
            default:
                cout << "\nInvalid input, try again." << endl;
            }
            resized_tale = table.resize_table(ball.diameter);
        }
        else if (object == 'b')
        {
            ball_methods_list();
            cin >> method;
            switch (method)
            {
            case '1':
                set_ball_starting_position(ball);
                break;
            case '2':
                set_ball_diameter(ball);
                resized_tale = table.resize_table(ball.diameter);
                break;
            default:
                cout << "Invalid input, try again." << endl;
            }
        }
        else if (object == 'h') 
        {
            // CHECKING IF BALL IS ON THE TABLE IS ONLY DONE WHEN ATTEMPTING TO HIT !!!
            if (ball.is_inTable(resized_tale) == false)
            {
                cout << "\nBall can't be hit" << endl;
                cout << "Current ball position (" << ball.currPosition << ") is not in the borders of the table!" << endl;
                continue;
            }
            try
            {
                Hit hit = hit_constructor();
                ball.hit_the_ball(hit, resized_tale);
            }
            catch (std::invalid_argument &invalid_power)
            {
                cout << "\nInvalid argument. Power must be in range [1,10]" << endl;
                continue;
            }
        }
        else if (object == 's')
        {
            show_results(table, ball);
        }
        else if (object == 'e')
            break;
        else
            cout << "\nInvalid input, try again." << endl;
    }

    cout << "Bye!" << endl;

    return 0;
}

void menu()
{
    cout << "\n\n\n------MAIN MENU------" << endl
         << endl;
    cout << "[t] - Table settings" << endl
         << "[b] - Ball settings" << endl
         << "[h] - Hit the Ball " << endl
         << "[s] - Show current results" << endl
         << "[e] - Exit" << endl
         << endl;
}

void table_methodslist()
{
    cout << " 1 - Simple table" << endl
         << " 2 - Complex table" << endl;
}

Table table_simple_case_constructor()
{
    Point p;
    double width, length;
    cout << "\nEnter corordinates (x, y) of bottom left corner: ";
    cin >> p;
    cout << "\nEnter lenght: ";
    cin >> length;
    cout << "\nEnter width: ";
    cin >> width;

    return Table(p, length, width);
}

Table table_complex_case_constructor()
{
    Point p1, p2, p3, p4;
    cout << "\nEnter corordinates (x, y) of the four corners: " << endl;
    cout << "\nEnter bottom left corner coordinates: ";
    cin >> p1;
    cout << "\nEnter bottom right corner coordinates: ";
    cin >> p2;
    cout << "\nEnter top right corner coordinates: ";
    cin >> p3;
    cout << "\nEnter top left corner coordinates: ";
    cin >> p4;

    return Table(p1, p2, p3, p4);
}

void ball_methods_list()
{
    cout << " 1 - Set current position" << endl
         << " 2 - Set diameter" << endl;
}

void set_ball_starting_position(Ball &ball)
{
    Point p;
    cout << "Enter the new starting coordinates (x, y) of the ball: ";
    cin >> p;

    ball.set_starting_position(p);
}

void set_ball_diameter(Ball &ball)
{
    double diameter;
    cout << "Enter the new diameter of the ball: ";
    cin >> diameter;

    ball.set_diameter(diameter);
}

Hit hit_constructor()
{
    Point direction_point;
    double power;
    cout << "Enter the coordinates (x, y) of the direction of the hit: ";
    cin >> direction_point;
    cout << "Enter the magnitude of the force of the hit: ";
    cin >> power;

    return Hit(power, direction_point);
}

void show_results(Table table, Ball ball)
{
    cout << "Field points: " << endl;
    cout << table.A << endl;
    cout << table.B << endl;
    cout << table.C << endl;
    cout << table.D << endl;

    cout << "Ball centre: " << ball.currPosition << endl;
    cout << "Ball diameter: " << ball.diameter << endl;
}