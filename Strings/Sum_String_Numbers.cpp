/*Напишете програма, която въвежда от клавиатурата
един ред (с дължина най-много 80 знака), на който
са написани две естествени числа, разделени със
знака плюс (+), намира сбора на двете числа 
и извежда на екрана резултата*/


#include <iostream> 
#include <string>
using namespace std;

int main()
{
	string N;
	cout << "Write an expression with +: ";
	cin >> N;

	size_t plus_pos = N.find('+');
	string num1 = N.substr(0, plus_pos);
	string num2 = N.substr(plus_pos + 1);
	int sum = stoi(num1) + stoi(num2);
	cout << sum;
}
