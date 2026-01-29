/*15 - Зададени са k окръжности 
(абсциса и ордината на центъра и радиус). 
Да се намерят всички двойки окръжности, които се
допират*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int k;
	cout << "Enter the number of circles: ";
	cin >> k;

	double xc[1000], yc[1000], r[1000];
	for (int i = 0; i < k; i++)
	{
		cout << "Circle " << i + 1 << "(xc yc r) = ";
		cin >> xc[i] >> yc[i] >> r[i];
	}

	double eps = 1e-6;
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			double dx = xc[i] - xc[j];
			double dy = yc[i] - yc[j];
			double dist = sqrt(dx * dx + dy * dy);
			if (abs(dist - (r[i] + r[j])) < eps || abs(dist - abs(r[i] - r[j])) < eps)
			{
				cout << "Circles " << i + 1 << " and " << j + 1 << " are tangent" << endl;
			}
			else 
			{
				cout << "There are no tangent circles";
			}
		}
	}
	return 0;
}
