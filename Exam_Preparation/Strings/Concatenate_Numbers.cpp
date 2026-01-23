/*Да се направи програма, която въвежда от
клавиатурата 5 естествени числа 
(написани на един ред) и извежда на екрана 
най-голямото число, което може да се получи
чрез написване на тези числа едно след 
друго в някаква последователност.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	return (a + b) > (b + a);
}

int main()
{
	string numbers[5];
	cout << "Enter 5 numbers:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Write the number: ";
		cin >> numbers[i];
	}
	sort(numbers, numbers + 5, compare);
	for (int i = 0; i < 5; i++)
	{
		cout << numbers[i];
	}
	cout << endl;
}
