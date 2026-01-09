// Да се състави рекурсивна функция за намиране 
// на най-големият общ делител 
// (НОД) на две цели числа.   


#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()  
{
	int x, y;
	cout << "Enter two numbers: ";
	cin >> x >> y;

	cout << "GCD = " << gcd(x, y);
	return 0;
}
