/* Дадени е масив от n целoчислени елемента.
 * Да се напише функции с програма, която намира:
 * - сумата от квадратните корени на четните
 * цифри на всeки елемент;
 * - намира елемента с най-голямата сума.
 */

#include <iostream>
#include <cmath>
using namespace std;

double square_roots_sum(int number)
{
    double sum = 0;
    number = abs(number);
    if (number == 0) return 0;

    while (number > 0) {
        int digit = number % 10;
        if (digit % 2 == 0) {
            sum += sqrt(digit);
        }
        number /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the number of the array: ";
    cin >> n;
    int A[100];

    int best_element = 0;
    double max_sum = -1.0;

    for (int i = 0; i < n; i++) {
        cout << "A["<< i + 1 <<"] = ";
        cin >> A[i];

        double current_sum = square_roots_sum(A[i]);
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_element = A[i];
        }
    }
    cout << "The biggest square root even digits sum is: " << best_element << endl;
    cout << "Result = " << max_sum << endl;
}
