/*Да се състави програма, чрез която се 
въвеждат n цели числа от интервала [-5000..5000] 
в едномерен масив. Програмата да изведе 
общата сума на въведените числа.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the count of numbers: ";
	cin >> n;

	int A[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> A[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += A[i];
	}
	cout << "Sum = " << sum << endl;
	return 0;
}
