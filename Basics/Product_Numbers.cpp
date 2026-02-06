/*Да се състави програма MULT.CPP, която чете от
 *клавиатурата цели числа, до въвеждане на числото 1,
 *и отпечатва произведението им. */

#include <iostream>
using namespace std;

int main()
{
    int a;
    long P = 1;
    do {
        cin >> a;
        P *= a;
    } while (a != 1);
    cout << P << endl;
}
