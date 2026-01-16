#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double PI = 3.14;
	double a, b, h;
	cin >> a >> b >> h;

	for (double deg = a; deg <= b; deg += h)
	{
		double rad = deg * PI / 180;

		cout << "deg = " << deg
			<< " sin = " << sin(rad)
			<< " cos = " << cos(rad)
			<< " tg = " << tan(rad);
		if (tan(rad) != 0)
			cout << " ctg = " << 1 / tan(rad);
		else
			cout << " ctg = undefined";
		cout << endl;
	}
	return 0;
}
