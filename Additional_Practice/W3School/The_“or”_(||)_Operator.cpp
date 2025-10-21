#include <iostream>
using namespace std;

int main() {
    
 cout << "Enter a number: ";
    int num {};
    cin >> num;
    if(num == 4 || num == 8)
        cout << "You chose a winning number!";
    else
        cout << "Sorry, better luck next time.";
    return 0;
}
