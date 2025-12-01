#include <iostream>
using namespace std;

int main()
{
	int n_triangles;
	cout << "Enter how many triangles you want: ";
	cin >> n_triangles;

	double* a = new double[n_triangles];
	double* b = new double[n_triangles];

	if (!a || !b)
	{
		cout << "Error: memory not allocated.\n";
		return 0;
	}

	for (int i = 0; i < n_triangles; i++)
	{
		cout << "Triangle " << i + 1 << ":\n";
		cout << " Side A: ";
		cin >> a[i];
		cout << "  Side B: ";
		cin >> b[i];
	}
	int max_index = 0;
	double max_area = 0;

	for (int i = 0; i < n_triangles; i++)
	{
		double area = (a[i] * b[i]) / 2.0;
		if (area > max_area)
		{
			max_area = area;
			max_index = i;
		}
	}
	cout << "\nTriangle with the largest area is number " << max_index + 1
		<< " with area = " << max_area << endl;

	delete[] a;
	delete[] b;

	return 0;

}
