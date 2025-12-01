#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many numbers you want: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements in ascending order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    cout << "Enter a new element to insert: ";
    cin >> x;

    int* new_arr = new int[n + 1];
    int i = 0, j = 0;

    while (i < n && arr[i] < x) {
        new_arr[j++] = arr[i++];
    }

    new_arr[j++] = x;

    while (i < n) {
        new_arr[j++] = arr[i++];
    }

    delete[] arr;
    arr = new_arr;
    n++;

    cout << "Array after insertion: ";
    for (int k = 0; k < n; k++)
        cout << arr[k] << " ";
    cout << endl;

    delete[] arr; 
    return 0;
}
