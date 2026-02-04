

/*73)Напишете програма за определяне цялата степен k,
 *на която трябва да се повдигне дадено число а>1,
 *за да се удовлетвори условието а^k≥b (b>1).
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter a = ..., (a > 1): ";
    cin >> a;

    cout << "Enter b = ..., (b > 1): ";
    cin >> b;


    int k = 0;
    long long power = 1;
    while (power < b) {
        power = power * a;
        k++;
    }
    cout << k << endl;
    return 0;
}
