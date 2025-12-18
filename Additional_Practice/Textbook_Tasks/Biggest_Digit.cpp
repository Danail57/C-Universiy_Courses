/*Да се напише програма, която проверява коя цифра на
дадено неотрицателно число се  среща най-голям брой
пъти в десетичния му знак.*/

#include <iostream>
using namespace std;

int main()
{
	int x = 0; // given number
	int max_digit = 0; // most frequent digit
	int count = 0; // how many max_digit is in the number
	int current_digit = 0;
	int max_count = 0; // encountering of current digit
	int temp = 0;

	cout << "Enter a positive number: ";
	cin >> x;
	for (int digit = 0; digit < 10; digit++)
	{
		temp = x;
		while (temp != 0)
		{
			if (temp % 10 == digit)
				count++;
			temp /= 10;
		}
		if (count > max_count)
		{
			max_digit = digit;
			max_count = count;
		}
	}
	cout << "Max digit is: " << max_digit << endl;
	return 0;
}
	
