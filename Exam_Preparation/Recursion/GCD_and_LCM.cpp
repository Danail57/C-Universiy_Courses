// Да се състави рекурсивна функция за намиране 
// на НОК и НОД на две цели числа.   


#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()  
{
	int x, y;
	cout << "Enter two numbers: ";
	cin >> x >> y;

	cout << "GCD = " << gcd(x, y);
	cout << endl;
	cout << "LCM = " << lcm(x, y);
	return 0;
}
