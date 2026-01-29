/*Напишете програма, която въвежда от клавиатурата
един ред (с дължина най-много 80 знака), на който
са написани две естествени числа, разделени със 
знака плюс (+), намира сбора на двете числа и 
извежда на екрана резултата.*/

#include <iostream> 
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	char line[81];
	cout << "Enter some expression with numbers and +: ";
	cin.getline(line, 81);

	int plus_pos = -1;
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '+')
		{
			plus_pos = i;
			break;
		}
	}
	if (plus_pos == -1)
	{
		cout << "'+' not found" << endl;
		return 1;
	}

	char num1_str[81];
	strncpy(num1_str, line, plus_pos);
	num1_str[plus_pos] = '\0';

	char num2_str[81];
	strcpy(num2_str, line + plus_pos + 1);

	int num1 = atoi(num1_str);
	int num2 = atoi(num2_str);
	int sum = num1 + num2;

	cout << "Sum = " << sum << endl;
	return 0;
}
