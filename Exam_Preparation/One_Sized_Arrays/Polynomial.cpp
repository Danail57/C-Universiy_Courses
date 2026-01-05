// Да се състави програма за пресмятане\
// на полином от степен n
// y = a0x + a1x pow(n - 1) + … + an - 1x + an
// по зададени n, коефициенти и x.

#include <iostream>
#include <cmath>
using namespace std;

double evaluate_polynomial(double coefficients[], int n, double x)
{
	double result = 0;
	for (int i = 0; i <= n; i++)
	{
		result += coefficients[i] * pow(x, n - i);
	}
	return result;
}


int main()
{
	int n;
	cout << "Enter degree n: ";
	cin >> n;

	double coefficients[100];
	cout << "Enter coefficients a0 to a" << n << ":\n";

	for (int i = 0; i <= n; i++)
	{
		cin >> coefficients[i];
	}
	double x;
	cout << "Enter x: ";
	cin >> x;

	double y = evaluate_polynomial(coefficients, n, x);
	cout << "Result y = " << y << endl;
	return 0;

}
