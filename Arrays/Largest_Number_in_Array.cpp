
/*4)Да се намери най-големият елемент в едномерен масив.
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
    for (int i = 0; i < n; i++) {
        if (A[i] > max_element) {
            max_element = A[i];
        }
    }
    cout << "The largest element is: " << max_element << endl;
}
