// Дадени са катетите на n правоъгълни триъгълника.
// Да се напише програма, която намира и извежда 
// номера и лицето на триъгълника 
// с най - голямо лице.

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter how many triangles you want to write: ";
	cin >> n;

	float* a = new float[n];
	float* b = new float[n];

	double area;
	double max_area = 0;
	int max_index = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Triangle " << i + 1 << " side a: ";
		cin >> *(a + i);

		cout << "Triangle " << i + 1 << " side b: ";
		cin >> *(b + i);

	}

	for (int i = 0; i < n; i++)
	{
		area = (*(a + i) * *(b + i)) / 2;
		if (area > max_area)
		{
			max_area = area;
			max_index = i + 1;
		}
	}
	cout << "Triangle with max area is number: " << max_index << endl;
	cout << "Max area: " << max_area << endl;

	delete[] a;
	delete[] b;
	return 0;
}
