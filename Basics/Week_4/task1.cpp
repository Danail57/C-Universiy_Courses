#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Enter number for n: ";
	cin >> n;
	double x[n], y[n];

	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	double total_length = 0;

	for (int i = 0; i < n - 1; i++)
	{
		double dx = x[i + 1] - x[i];
		double dy = y[i + 1] - y[i];
		total_length += sqrt(dx * dx + dy * dy);
	}
	cout << "Total length; " << total_length << endl;
	return 0;
}
