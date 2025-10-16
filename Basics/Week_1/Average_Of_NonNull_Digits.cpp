# Да се състави програма, която извежда средно-аритметичното на ненулевите цифри на зададено цяло число. 
  
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
    int number, non_null_digit;
    int sum_non_null_digits = 0, count_non_null_digits = 0;
    double average;

    cout << "Enter your number: ";
    cin >> number;

    number = abs(number);

    while (number > 0) 
    {
        non_null_digit = number % 10;

        if (non_null_digit != 0)
        {
            sum_non_null_digits += non_null_digit;
            count_non_null_digits += 1;
        }

        number /= 10;  
    }

    if (count_non_null_digits == 0)
    {
        average = 0;
    }
    else
    {
        average = static_cast<double>(sum_non_null_digits) / count_non_null_digits;
    }

    cout << fixed << setprecision(2);
    cout << "The average of non-zero digits is: " << average << endl;

    return 0;
}
