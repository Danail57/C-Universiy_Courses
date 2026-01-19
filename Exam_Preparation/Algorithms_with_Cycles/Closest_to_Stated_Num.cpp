/*  Да се състави алгоритъм, 
който въвежда цели числа докато 
сумата им стане по-голяма или равна
на зададено число М. 
Програмата извежда поредния номер 
на онова число от въведените числа, 
което е най близко до зададено число М. */

#include <iostream>
#include <climits>
using namespace std;


int main()
{
	int M;

	int closest_diff = INT_MAX;
	int closest_number_index = 0;
	int total_numbers = 0;
	int sum = 0;
	int number;

	while (sum < M)
	{
		cout << "Write a number: ";
		cin >> number;
		total_numbers++;
		sum += number;
		
		int diff = abs(M - number);

		if (diff < closest_diff)
		{
			closest_diff = diff;
			closest_number_index = total_numbers;
		}		
	}
	cout << "Position of the closest number to M: " << closest_number_index << endl;
}
