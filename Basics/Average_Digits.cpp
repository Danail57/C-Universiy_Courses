# Да се състави програма, която извежда средно-аритметичното на цифрите на зададено цяло число.  

#include <iostream> 
using namespace std;

int main()
{
    int number, digit, sum = 0, count = 0;
    double average = 0;
    
    cout << "Enter your number: ";
    cin >> number;
    
    number = abs(number);
    
    
    if (number == 0)
    {
        average = 0;
        count = 1;
    }
    
    else
    {
    
    while (number > 0)
    {
        digit = number % 10;
        sum += digit;
        count += 1;
        number /= 10;
    }
