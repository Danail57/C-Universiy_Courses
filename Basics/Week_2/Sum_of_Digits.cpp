# Да се състави програма, която извежда сумата на цифрите на зададено цяло число. 

# include <iostream>
using namespace std;

int main () {
    int number, digit, sum = 0;
    
    cout << "Enter your number: ";
    cin >> number;
    
    number = abs(number);
    
    while (number > 0) {
        digit = number % 10;
        sum += digit;
        number /= 10;
    }
    cout << "The sum is: " << sum << endl;
    return 0;
}
