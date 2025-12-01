#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int power_n;
	cout << "Enter the power: ";
	cin >> power_n;

	double* coeff = new double[power_n + 1];

	cout << "Enter the coefficients a0, a1, ..., an:\n";

	for (int i = 0; i <= power_n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> coeff[i];
	}

	double x;
	cout << "Enter a number for x: ";
	cin >> x;

	double y = 0;

	for (int i = 0; i <= power_n; i++)
	{
		y = y * x + coeff[i];
		cout << y;
	}
	cout << "\nResult y = " << y << endl;
	delete[] coeff;
	return 0;
}
