/*Напишете програма, която въвежда две различни
цели числа в променливите a и b, след което 
на променливата, която има помалка стойност,
присвоява сумата на двете въведени числа, 
а на другата променлива присвоява
произведението на двете въведени числа.*/

#include <iostream>
using namespace std;

int main()
{
	int a, b, product = 1, sum = 0;
	cout << "Enter two numbers: ";
	cin >> a >> b;

	product = a * b;
	sum = a + b;
	cout << "Sum = " << sum << endl;
	cout << "Product = " << product << endl;
	return 0;
}
