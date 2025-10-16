#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double number = 0.5;  
    double function;

    cout << fixed << setprecision(2);

    while (number <= 1.5) {
        function = number * number;
        cout << "number = " << number << ", function = " << function << endl;
        number += 0.1;
    }
    return 0;
}
