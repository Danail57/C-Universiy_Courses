/*Дадени са N естествени числа.
За всяко число да се изведе друго естествено число,
което има същата сума на цифрите.
За всяко число да се генерира най-малкото възможно
число, което има същата сума на цифрите.
За всяко число да се генерира най-голямото възможно
число, което има същата сума на цифрите.*/

#include <iostream>
#include <string>
using namespace std;

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

string min_number(int sum)
{
	string result = "";
	while (sum > 9)
	{
		result = '9' + result;
		sum -= 9;
	}
	if (sum > 0)
		result = char('0' + sum) + result;
	return result;
}

string max_number(int sum)
{
	string result = "";
	while (sum > 9)
	{
		result += '9';
		sum -= 9;
	}
	if (sum > 0)
		result += char('0' + sum);
	return result;
}

int main()
{
	int N;
	cin >> N;
	int A[1000];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		int s = digit_sum(A[i]);
		cout << "Original: " << A[i] << endl;
		cout << "Min: " << min_number(s) << endl;
		cout << "Max: " << max_number(s) << endl;
	}
	return 0;
}
