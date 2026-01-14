/*Напишете програма, която пресмята скаларното
произведение на два вектора*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

int main()
{
	cout << "Enter a number n from 1 to " << MAX_SIZE << ": ";
	int n;
	cin >> n;

	double a[MAX_SIZE];
	int i;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}

	double b[MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		cout << "b[" << i + 1 << "] = ";
		cin >> b[i];
	}
	double scalar_multiplication = 0;
	for (int i = 0; i < n; i++)
		scalar_multiplication = scalar_multiplication + a[i] * b[i];
	cout << "Scalar multiplication of the two vectors is: " << scalar_multiplication << endl;
	return 0;
}
