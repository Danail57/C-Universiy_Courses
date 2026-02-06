/*Дадено е трицифрено число k.
 *Да се състави програма SUMCIF.CPP,
 *която прочита от клавиатурата числото k
 *и отпечатва сумата от цифрите му. */

#include <iostream>
using namespace std;

int main()
{
    int k;
    cout << "Enter a number between 100 and 999: ";
    cin >> k;

    int hundreds = k / 100; // първата цифра - стотици
    int tens = (k / 100) % 10; // взимаме втората цифра - десетици
    int units = k % 10; // последната цифра - единици
    int sum = hundreds + tens + units;
    cout << "Digits sum = " << sum << endl;
}
