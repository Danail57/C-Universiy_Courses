# Да се състави програма, която извежда сумата на четните цифри на зададено цяло число.

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int number, digit, sum = 0;
    cout << "Enter your number: ";
    cin >> number;
    
    number = abs(number);
    
    while (number > 0) {
        digit = number % 10;          
        if (digit % 2 == 0) {         
            sum += digit;             
        }
        number /= 10;               
    }

    cout << "The even digit sum is: " << sum << endl;
    return 0;
}
