# Да се напише програма, проверяваща дали дадена точка принадлежи към даден квадрант и дали съвпада с абсцисата и ординатата.

#include <iostream>
using namespace std;


int main() 
{
    double x;
    double y;
    
    cout << "Enter the coordinates for x: ";
    cin >> x;
    
    cout << "Enter the coordinates for y: ";
    cin >> y;
    
    if (x == 0 && y == 0)
    { cout << "The point coincides with the center of the coordinate system."; return 0;}
    
    if (x == 0)
    {cout << "The point is on Oy line.";
        return 0;
    }

    if (y == 0)
    {cout << "The point is on Ox line.";
        return 0;
    }
    
    if (x > 0 && y > 0)
    {cout << "The point is in the first quadrant.";
        return 0;
    }
    
    if (x < 0 && y > 0)
    {cout << "The point is in the second quadrant.";
        return 0;
    }
    
    if (x < 0 && y < 0)
    {cout << "The point is in the third quadrant.";
        return 0;
    }
    
    if (x > 0 && y < 0)
    {cout << "The point is in the fourth quadrant.";
        return 0;
    }
}
