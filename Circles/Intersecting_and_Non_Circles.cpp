/*13, 14) Зададени са k окръжности 
(абсциса и ордината на центъра и радиус). 
Да се намерят всички двойки окръжности,
които не се пресичат и се пресичат*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int k;
	cout << "Enter the number of circles: ";
	cin >> k;

	double x[1000], y[1000], r[1000];
	for (int i = 0; i < k; i++)
	{
		cout << "Circle " << i + 1 << " (x y r) = ";
		cin >> x[i] >> y[i] >> r[i];
	}
	cout << "Non-intersecting pairs:\n";
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			double dx = x[i] - x[j];
			double dy = y[i] - y[j];
			double dist = sqrt(dx * dx + dy * dy);
			if (dist > r[i] + r[j] || dist < fabs(r[i] - r[j]))
			{
				cout << "Circle " << i + 1 << " and circle " << j + 1 << " do not intersect\n";
			}
		}
	}
	cout << "Intersecting pairs:\n";
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			double dx = x[i] - x[j];
			double dy = y[i] - y[j];
			double dist = sqrt(dx * dx + dy * dy);
			if (dist <= r[i] + r[j] && dist >= fabs(r[i] - r[j]))
			{
				cout << "Circle " << i + 1 << " and circle " << j + 1 << " intersect.\n";
			}
		}
	}
	return 0;
}
