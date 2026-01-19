/* Да се състави алгоритъм, който последователно
въвежда цели числа докато сумата им стане M 
или броят им стане N и намира поредния номер 
на най-малкото от въведените числа.  */

#include <iostream>
using namespace std;


int main()
{
	int N, M;
	cout << "Enter N (max count): ";
	cin >> N;

	cout << "Enter M (target sum): ";
	cin >> M;

	int sum = 0;
	int count = 0;
	int x, min_value;
	int min_position = 0;

	while (count < N && sum < M)
	{
		cout << "Enter number: ";
		cin >> x;
		sum += x;
		count++;
		if (count == 1 || x < min_value)
		{
			min_value = x;
			min_position = count;
		}
	}
	cout << "Position of the smallest number: " << min_position << endl;
	return 0;
}
