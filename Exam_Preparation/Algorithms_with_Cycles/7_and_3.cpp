/* . Да се състави алгоритъм, който проверява\
дали зададено цяло число съдържа цифрата 3. 
 Да се състави алгоритъм, който проверява 
 дали втората цифра на зададено цяло число  е 7.
 */

#include <iostream>
using namespace std;

bool contains_three(int number)
{
	number = abs(number);
	while (number > 0)
	{
		if (number % 10 == 3)
			return true;
		number /= 10;
	}
	return false;
}

bool second_digit_is_seven(int number)
{
	number = abs(number);

	// checking if there is no second digit
	if (number < 10)
		return false;

	// get rid of the last digit
	number /= 10;
	return (number % 10 == 7);
}

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	if (contains_three(n))
		cout << "The number contains digit 3." << endl;
	else
		cout << "The number does not contain digit 3." << endl;

	if (second_digit_is_seven(n))
		cout << "The second digit is 7." << endl;
	else
		cout << "The second digit is not 7." << endl;

	return 0;
}
