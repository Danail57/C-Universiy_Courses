#include <iostream>
using namespace std;

int main()
{
	int n, digit;
	int reversed_number = 0;
	
	cout << "Enter a number: ";
	cin >> n;

	while (n > 0)
	{
		digit = n % 10;
		reversed_number = reversed_number * 10 + digit;
		n = n / 10;
	}
	cout << "Reversed number: " << reversed_number << endl;
	return 0;
}
