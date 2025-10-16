# Да се състави програма, която извежда сумата на цифрите на зададено цяло число, които са между 3 и 6. 

#include <iostream>
using namespace std;

int main () 
{
    int number, digit, sum = 0;
    cout << "Enter your number: ";
    cin >> number;
    
    number = abs(number);
    
    while (number > 0) 
    {
        digit = number % 10;
        
        if (digit >= 3 && digit <= 6)
        {
            sum += digit;
        }
        
        number /= 10;
    }
    cout << "The sum of digits between 3 and 6 is: " << sum << endl;
    return 0;
}
