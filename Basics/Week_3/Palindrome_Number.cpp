//  напишете програма която проверява дали две числа са палиндроми?

#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter your number: ";
    cin >> number;
    
    int original_number = number;
    int reversed_number = 0;
    
    while (number > 0)
    {
        int digit = number % 10;
        reversed_number = reversed_number * 10 + digit;
        number = number / 10;
        
    }
    if (original_number == reversed_number)
    
        cout << "The number is a palindrome." << endl;
    else
        cout << "The number is NOT a palindrome." << endl;
    
    
    return 0;
}
