// Да се състави алгоритъм за намиране индекса
// на елемента с най - голяма стойност
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

	int max_index = 0;

	for (int i = 1; i < n; i++)
	{
		if (p[i] > p[max_index])
		{
			max_index = i;
		}
	}

	cout << " The biggest element is p[" << max_index << "] = " << p[max_index] << endl;

	return 0;
}
