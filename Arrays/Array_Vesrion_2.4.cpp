
/*4)Задача с масив.
*/

#include <iostream>
using namespace std;


int main()
{
    int n;
    cout << "Enter the count of array: ";
    cin >> n;

    int A[100];
    for (int i = 0; i < n; i++) {
        cout << "A["<< i + 1 <<"] = ";
        cin >> A[i];
    }
    int max_element = A[0];
    double sum = 0;
    double difference = A[0];
    int min_value = A[0];
    int min_index = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (i > 0)
            difference -= A[i];
        if (A[i] < min_value) {
            min_value = A[i];
            min_index = i;
        }

        if (A[i] > max_element) {
            max_element = A[i];
        }
    }
    double average = sum / n;
    cout << "\nSum = " << sum << endl;
    cout << "Difference = " << difference << endl;
    cout << "Average = " << average << endl;
    cout << "Smallest number is A[" << min_index + 1 << "] = " << min_value << endl;
    cout << "The largest element is: " << max_element << endl;
}
