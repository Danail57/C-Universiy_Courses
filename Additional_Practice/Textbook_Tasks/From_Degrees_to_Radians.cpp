# Да се напише програма за превръщане от градуси в радиани

#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14;

int main ()
{
    double alpha;
    cout << "Enter the degrees: ";
    cin >> alpha;
    
    double alpha_radians;
    alpha_radians = PI / 180 * alpha;
    
    cout << fixed << setprecision(2);
    cout << alpha << " Degrees equal to " << alpha_radians << " radians.";
    return 0;
}
