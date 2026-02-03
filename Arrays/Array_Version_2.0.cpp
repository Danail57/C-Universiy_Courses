
/*4) Даден е едномерен масив от n цели числа.
Да се:
Намери средното аритметично на отрицателните елементи
Намерят всички елементи, които се делят на 7,
и да се изчисли тяхната сума
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the count of the array: ";
    cin >> n;

    int A[100];
    for (int i = 0; i < n; i++) {
        cout << "A[" << i + 1<< "] = ";
        cin >> A[i];
    }
    int sum_negative = 0;
    int count_negative = 0;
    int sum_divide_by_7 = 0;

    cout << "Numbers divisible by 7: ";
    cout << endl;
    for (int i = 0; i < n; i++){
        if (A[i] % 7 == 0) {
            cout << A[i] << " ";
            sum_divide_by_7 += A[i];
        }

        if (A[i] < 0) {
            sum_negative += A[i];
            count_negative++;
        }
    }
    cout << endl;
    if (count_negative > 0)
    {
        double average = double(sum_negative) / count_negative;
        cout << "Average of negative numbers = " << average << endl;

    }
    else
    {
        cout << "Sum of numbers divisible by 7 = " << sum_divide_by_7 << endl;
    }
}
