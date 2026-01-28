/*11) Зададени са k окръжности
(абсциса и ордината на центъра и радиус) 
и m точки в равнината (абсциса и ордината). 
Да се намери най-отдалечена точка от центъра 
на всяка окръжност.*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int k;
	cout << "Enter the number of circles: ";
	cin >> k;

	double cx[1000], cy[1000], r[1000];
	for (int i = 0; i < k; i++)
	{
		cout << "Point " << i + 1 << " (xc yc r) = ";
		cin >> cx[i] >> cy[i] >> r[i];
	}

	int m;
	cout << "Enter the number of points: ";
	cin >> m;

	double px[1000], py[1000];

	for (int i = 0; i < m; i++)
	{
		cout << "Point " << i + 1 << "(x y) = ";
		cin >> px[i] >> py[i];
	}
	for (int i = 0; i < k; i++)
	{
		double max_dist = -1;
		int best_point = -1;
		for (int j = 0; j < m; j++)
		{
			double dx = px[j] - cx[i];
			double dy = py[j] - cy[i];
			double dist = sqrt(dx * dx + dy * dy);
			if (dist > max_dist)
			{
				max_dist = dist;
				best_point = j;
			}
		}
		cout << "For circle " << i + 1 << ", farthest point is: ";
		cout << "Point " << best_point + 1 << " (" << px[best_point] << ", " << py[best_point] << ")" << endl;
	}
	return 0;
}
