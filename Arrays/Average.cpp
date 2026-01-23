/*Да се състави програма, чрез която се 
въвеждат 7 цели числа от интервала [-5000..5000]
в едномерен масив.
Програмата да изведе средната стойност 
на въведените числа.*/

#include <iostream>
using namespace std;

int main()
{
	int A[7];
	double average = 0;
	int sum = 0;

	for (int i = 0; i < 7; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	average = sum / 7.0;
	cout << "Average = " << average << endl;
	return 0;
}
