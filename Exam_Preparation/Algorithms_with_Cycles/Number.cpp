/*Да се напише програма, която въвежда от 
клавиатурата едно цяло число. 
Ако числото е кратно на 3, 
програмата трябва да изведе същото число.
Ако то е кратно на 7, програмата трябва 
да пресметне произведението на числото 
с 4 и да изведе резултата.
Ако числото не е кратно нито на 3, нито на 7,
програмата трябва да изведе 0.*/

#include <iostream>
using namespace std;

int main()
{
	int number;
	int product = 1;
	cout << "Enter a number: ";
	cin >> number;

	if (number % 3 == 0)
	{
		cout << number;
	}
	else if(number % 7 == 0)
	{
		product = number * 4;
		cout << product;
	}
	else
	{
		cout << 0;
		return 0;
	}
	return 0;
}
