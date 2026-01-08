// print a multiplication table
// for any given number


#include <iostream>
using namespace std;

int main()
{
	int num, i, result;
	cout << "Enter a number: ";
	cin >> num;

	for (int i = 1; i <= 100; i++)
	{
		result = num * i;
		cout << num << " * " << i << " = " << result;
		cout << endl;
	}
	cout << endl;
	return 0;
}
