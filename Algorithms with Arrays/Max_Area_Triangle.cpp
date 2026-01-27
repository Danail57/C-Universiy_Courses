/*8) Дадени са два масива a и b, които 
съдържат катетите на m правоъгълни 
триъгълници. Да се намери номера на 
триъгълника с най-голямо лице.*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int m;
	cout << "Enter the number of triangles: ";
	cin >> m;

	int a[1000], b[1000];
	for (int i = 0; i < m; i++)
	{
		cout << "Triangle " << i + 1 << " - enter catheti A and B: ";
		cout << "A[" << i + 1 << "] = ";

		cin >> a[i];

		cout << "B[" << i + 1 << "] = ";
		cin >> b[i];
	}

	int max_index = 0;
	double max_area = (a[0] * b[0]) / 2.0;
	for (int i = 1; i < m; i++)
	{
		double area = (a[i] * b[i]) / 2.0;
		if (area > max_area)
		{
			max_area = area;
			max_index = i;
		}
	}
	cout << "Triangle with the largest area is number: " << max_index + 1 << endl;
	cout << "Area = cm" << max_area << endl;
}
