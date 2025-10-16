# include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    int sum = 0;
    int n = abs(number);

    while (n > 0) {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }
    cout << "Sum of digits: " << sum << endl;
    return 0;
}

// % 10 — взима последната цифра

//  /10 — маха последната цифра
