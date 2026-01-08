// Write a programme to check if a number
// is an Armstrong number 
// (number that equals the sum of its own digits, 
// where each digit is raised to 
// the power of the number of digits.).


#include <iostream>
using namespace std;

int main()
{
	int num, temp, digit = 0, result = 0, rem, pow, i;
	cout << "Enter the number: ";
	cin >> num;

	temp = num;
	while (num > 0)
	{
		num = num / 10;
		digit++;
	}
	num = temp;
	while (num > 0)
	{
		rem = num % 10;
		pow = 1;
		i = 0;
		while (i < digit)
		{
			pow = pow * rem;
			i++;
		}
		result = result + pow;
		num = num / 10;
	}
	if (result == temp)
		cout << "\nIt is an Amstrong number";
	else
		cout << "\nIt is not an Amstrong number";
	cout << endl;
	return 0;
}
