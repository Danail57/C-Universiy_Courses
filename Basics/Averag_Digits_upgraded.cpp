#include <iostream> 
using namespace std;

int main()
{
    int number, digit, sum = 0, count = 0;
    int even_count = 0, odd_count = 0;
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
        
        if (digit % 2 == 0)
        {
            even_count += 1;
        }
        else
        {
            odd_count += 1;
        }
        
        
        number /= 10;
    }
    average = double(sum) / count;
        
    }
    cout << "The average of digits is: " << average << endl;
    cout << "The even count digits are: " << even_count << endl;
    cout << "The odd count digits are: " << odd_count << endl;
    return 0;
    
}
