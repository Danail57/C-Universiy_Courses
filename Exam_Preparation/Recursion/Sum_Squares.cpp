// Да се състави програма с рекурсивна функция 
// за намиране на сумата от квадратите на
// целите числа от 1 до n.  


#include <iostream>
using namespace std;

int sum_squares(int n)
{
	if (n == 0)
		return 0;
	return n * n + sum_squares(n - 1);
}

int main()
{
	int n;
	cout << "Write a number: ";
	cin >> n;

	cout << "Sum of squares = " << sum_squares(n);
	return 0;
}
