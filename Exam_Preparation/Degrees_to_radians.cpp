#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, h;
	cin >> a >> b >> h;

	for (double x = a; x <= b; x += h)
	{
		cout << "x = " << x << ", sin(x) = " << sin(x) << endl;
	}
	return 0;
}
