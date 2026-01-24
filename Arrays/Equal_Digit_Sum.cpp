/*Да се състави програма, чрез която се
въвежда N [3..35] броя естествени числа от 
интервала [10..10010].
За всяко въведено число програмата да 
генерира друго естествено число, така че 
всяка двойка съседни числа - въведено и генерирано 
да имат равни максимални суми.

да се генерира друго естествено число с 
равна максимална сума*/

int digit_sum(int x)
{
	int s = 0;
	while (x > 0)
	{
		s += x % 10;
		x /= 10;
	}
	return s;
}

int generate_number(int sum)
{
	int result = 0;
	while (sum > 9)
	{
		result = result * 10 + 9;
		sum -= 9;
	}
	result = result * 10 + sum;
	return result;
}

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "How many numbers you want? ";
	cin >> n;

	int A[35];
	int B[35];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> A[i];
		int s = digit_sum(A[i]);
		B[i] = generate_number(s);
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " -> " << B[i] << endl;
	}
	return 0;
}
