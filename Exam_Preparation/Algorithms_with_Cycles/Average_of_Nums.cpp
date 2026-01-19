/*  Да се състави алгоритъм, който иска
да въвеждаме цели числа, докато броят на 
въведените положителни числа стане N или
броят на въведените нулеви числа стане М. 
Програмата  извежда средно-аритметичното 
на всички въведени числа.   */

#include <iostream>
using namespace std;


int main()
{
	int N, M;
	cout << "Enter N (max count): ";
	cin >> N;

	cout << "Enter M (non zero nums): ";
	cin >> M;

	int count_positive = 0;
	int count_zero = 0;
	int total_numbers = 0;
	double sum = 0;
	int number;

	while (count_positive < N && count_zero < M)
	{
		cout << "Write a number: ";
		cin >> number;

		sum += number;
		total_numbers++;

		if (number > 0)
			count_positive++;
		else if (number == 0)
			count_zero++;
	}
	double average = sum / total_numbers;
	cout << "Average = " << average << endl;
	return 0;
}
