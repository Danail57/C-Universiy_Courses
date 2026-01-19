/*Да се състави алгоритъм, 
който последователно въвежда цели числа. 
Когато броят на въведените ненулеви числа 
стане N или броят на въведените нулеви
числа стане 2, въвеждането се прекратява 
и се извежда средно аритметичното 
на четните и броят на нечетните 
от въведените числа. N e зададено.  */

#include <iostream>
using namespace std;


int main()
{
	int N;
	cout << "Enter a number: ";
	cin >> N;

	int non_null_nums = 0;
	int zero_count = 0;
	int sum_evens = 0;
	int count_evens = 0;
	int count_odds = 0;
	int number;

	while (non_null_nums < N && zero_count < 2)
	{
		cout << "Enter a new number: ";
		cin >> number;

		if (number == 0)
		{
			zero_count++;
		}
		else
		{
			non_null_nums++;
			if (number % 2 == 0)
			{
				sum_evens += number;
				count_evens++;
			}
			else
			{
				count_odds++;
			}
		}
	}
	double average_evens = (count_evens ? sum_evens / (double)count_evens : 0);
	cout << "Average of even numbers: " << average_evens << endl;
	cout << "Count of odd numbers: " << count_odds << endl;
	return 0;
}
