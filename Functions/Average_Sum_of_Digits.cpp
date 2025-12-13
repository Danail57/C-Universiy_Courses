/*Да се намери при кое от две зададени цели числа
средноаритметичното на цифрите е по-голяма.*/

#include <iostream>
using namespace std;

double average_sum_of_digits(int n)
{
	int average_sum = 0;
	int count = 0;
	n = abs(n);

	while (n > 0)
	{
		int digit = n % 10; // taking the lst digit
		average_sum += digit; // adding to the sum
		count++; // increasing the number of digits
		n /= 10;
	}
	
	if (count == 0)
		return 0;
	return static_cast<double>(average_sum) / count;
	// Проврка за делене на нула, но тази проверка
	// предотвартява прекъсване на програмата, а просто 
	// извежда резултат 0.
}

int main()
{
	int a, b;
	cout << "Enter the first number: ";
	cin >> a;

	cout << "Enter the second number: ";
	cin >> b;

	double avg_a = average_sum_of_digits(a);
	double avg_b = average_sum_of_digits(b);

	if (avg_a > avg_b)
		cout << a << " has the larger average of digits: " << avg_a << endl;
	else if (avg_b > avg_a)
		cout << b << " has the larger average of digits: " << avg_b << endl;
	else
		cout << "Both numbers have the same average of digits: " << avg_a << endl;

	return 0;
}
