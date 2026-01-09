// Да се състави програма с рекурсия
// за превръщане на  цяло десетично 
// число в двоично. 

#include <iostream>
using namespace std;

void print_binary(unsigned long long n)
{
	if (n == 0)
		return;
	print_binary(n / 2);
	cout << n % 2;
}

int main()
{
	unsigned long long number;
	cout << "Enter a number: ";
	cin >> number;
	if (number == 0)
		cout << 0;
	else
		print_binary(number);
	return 0;
}
