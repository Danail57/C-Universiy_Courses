// Да се състави алгоритъм за намиране индекса
// на елемента с най - малка стойност
// сред елементите p1, p2, ..., pn от даден масив.

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of the elements: ";
	cin >> n;

	int p[1000];

	for (int i = 0; i < n; i++)
	{
		cout << "p[" << i << "] = ";
		cin >> p[i];
	}

	int min_index = 0;

	for (int i = 1; i < n; i++)
	{
		if (p[i] < p[min_index])
		{
			min_index = i;
		}
	}

	cout << "Smallest element is p[" << min_index << "] = " << p[min_index] << endl;

	return 0;
}
