/*Print the numbers in words*/

#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;

	if (number == 0)
	{
		cout << "zero";
		return 0;
	}
	string words[] = { "zero", "one", "two", "three", "four",
					  "five", "six", "seven", "eight", "nine" };

	int reversed = 0;
	int n = number;
	
	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}
	while (reversed > 0)
	{
		int digit = reversed % 10;
		cout << words[digit] << " ";
		reversed /= 10;
	}
	cout << endl;
	return 0;
}
