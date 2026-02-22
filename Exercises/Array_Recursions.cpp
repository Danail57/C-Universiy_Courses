/*Да се напише рекурсивна програма на с++,
 *която намира сумата на онези елементи в
 *едномерен масив от числа които са четни,
 *степени на двойката и са прости
 */

#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; n >= i * i; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_power_of_two(int n)
{
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

int sum_recursive(int arr[], int size)
{
    if (size <= 0) return 0;
    int curr = arr[size - 1];
    int sum = 0;

    if (curr % 2 == 0 && is_prime(curr) && is_power_of_two(curr)) {
        sum = curr;
    }
    return sum + sum_recursive(arr, size - 1);
}

int main()
{
    int n;
    cout << "Enter the number of the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Write the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element[" << i + 1 << "] = ";
        cin >> arr[i];
    }
    int result = sum_recursive(arr, n);
    cout << result << endl;
    delete [] arr;
    return 0;
}
