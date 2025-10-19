#  Да се напише програма, която посредством поразредни (побитови) логически операции проверява
#  дали дадено цяло число е точна степен на 2

#include  <iostream>
using namespace std;

bool is_power_of_two(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main ()
{
    int number;
    cout << "Enter your number: ";
    cin >> number;
    
    if (is_power_of_two(number)) {
        cout << number << " is a power of 2" << endl;} else {
            cout << number << " is not a power of 2" << endl;}
    return 0;
}
