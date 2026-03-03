/*Да се реализира като съставна програма следната задача
 Зададен е едномерен масив от цели числа
 А0, А1,...,Аn-1, където n e кратно на 2.
 Да се състави програма, която изчислява разликата
 между средно-аритметичното на елементите 
 от първата половина и средно-аритметичното 
 на елементите от втората половина на масива.  
 */


#include <iostream>
using namespace std;

double average_difference_in_array(int array[], int n)
{
	double sum_first = 0;
	double sum_second = 0;

	for (int i = 0; i < n / 2; i++)
	{
		sum_first += array[i];
	}
	for (int i = n / 2; i < n; i++)
	{
		sum_second += array[i];
	}
	double average_first = sum_first / (n / 2);
	double average_second = sum_second / (n / 2);
	return average_first - average_second;
}

int main()
{
	int n;
	cout << "Enter how many elements you want? ";
	cin >> n;

	int arr[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Element " << i + 1 << ": ";
		cin >> arr[i];
	}
	double result = average_difference_in_array(arr, n);
	cout << "Average diff = " << result << endl;
	return 0;
}
