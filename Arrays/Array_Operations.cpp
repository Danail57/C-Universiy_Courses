
/*9) Програма с масив. Целта е да се прехвърлят
 *положителните елементи в нов масив, да се
 *намери average на отрицателните елементи
 *и да запомня индексите на нулевите елементи в нов масив
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the count of the array: ";
    cin >> n;

    int A[450];
    for (int i = 0; i < n; i++)
    {
        cout << "A["<< i + 1 << "] = ";
        cin >> A[i];
    }

    int positive[450];
    int zero_indices[450];
    int k = 0, p = 0;
    double sum_negative = 0;
    int count_negative = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            positive[k++] = A[i];
        }
        else if (A[i] < 0)
        {
            sum_negative += A[i];
            count_negative++;
        }
        else
        {
            zero_indices[p++] = i;
        }
    }
    cout << "Positive numbers: ";
    for (int i = 0; i < k; i++)
        cout << positive[i] << " ";
    cout << endl;

    if (count_negative > 0)
        cout << "Average negatives = " << sum_negative / count_negative << endl;
    else
        cout << "No negatives in the array" << endl;

    if (p > 0)
    {
        cout << "Indices of zeros: ";
        for (int i = 0; i < p; i++)
            cout << zero_indices[i + 1] << " ";
        cout << endl;
    }
    else
    {
        cout << "No zeros in the array" << endl;
    }
}
