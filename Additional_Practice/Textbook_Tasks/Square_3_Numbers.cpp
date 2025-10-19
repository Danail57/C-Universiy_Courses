# Да се напише програма, извеждаща средно квадратичното на 3 числа.

#include <iostream>
#include <cmath>
using namespace std;

int  main ()
{
    int a, b, c;
    cout << "Enter your first number: ";
    cin >> a;
    
    cout << "Enter your second number: ";
    cin >> b;
    
    cout << "Enter your third number: ";
    cin >> c;
    
    double square_average = sqrt((a*a + b*b + c*c) / 3);
    cout << "The square average of the three numbers is: " << square_average << endl;
    return 0;
}
