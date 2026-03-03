/*Да се реализира като съставна програма следната задача
 Зададен е едномерен масив от цели числа 
 А0, А1,...,Аn-1, където n e кратно на 2.
 Да се състави програма, която изчислява разликата
 между сумата на елементите от първата половина и 
 сумата на елементите от втората половина на масива.
 */


#include <iostream>
using namespace std;

int difference_in_array(int array[], int n)
{
	int sum_first = 0;
	int sum_second = 0;

	for (int i = 0; i < n / 2; i++)
	{
		sum_first += array[i];
	}

	for (int i = n / 2; i < n; i++)
	{
		sum_second += array[i];
	}
	int diff = sum_first - sum_second;
	return diff;
}

int main()
{
	int n;
	cout << "How many numbers you want to write? ";
	cin >> n;

	int arr[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Element " << i + 1 << ": ";
		cin >> arr[i];
	}
	int result = difference_in_array(arr, n);
	cout << "Diffeence = " << result << endl;
	return 0;
}
