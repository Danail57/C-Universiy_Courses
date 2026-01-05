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

	double S_area;
	double max_area = 0;
	float a, b;
	int max_index_area = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the side: ";
		cin >> a;

		cout << "Enter the second side: ";
		cin >> b;

		S_area = (a * b) / 2;

		if (S_area > max_area)
		{
			max_area = S_area;
			max_index_area = i + 1;
		}
	}
	cout << "Triangle with max area is number: " << max_index_area << endl;
	cout << "max area: " << max_area << endl;
	return 0;
}
