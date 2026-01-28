/*11) Зададени са k окръжности 
(абсциса и ордината на центъра и радиус) 
и m точки в равнината (абсциса и ордината).
Да се намери най-близката точка до центъра на 
всяка окръжност.*/

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
		cout << "Circle " << i + 1 << " (x y r) = ";
		cin >> xc[i] >> yc[i] >> r[i];
	}

	int m;
	cout << "Enter the number of points: ";
	cin >> m;
	
	//масиви за точките
	double px[1000], py[1000];
	for (int i = 0; i < m; i++)
	{
		cout << "Point " << i + 1 << " (x y) = ";
		cin >> px[i] >> py[i];
	}

	for (int i = 0; i < k; i++)
	{
		int best_point = 0;
		double dx = px[0] - xc[i];
		double dy = py[0] - yc[i];
		double min_dist = sqrt(dx * dx + dy * dy);
		
		for (int j = 1; j < m; j++)
		{
			dx = px[j] - xc[i];
			dy = py[j] - yc[i];
			double dist = sqrt(dx * dx + dy * dy);
			if (dist < min_dist)
			{
				min_dist = dist;
				best_point = j;
			}
		}
		cout << "For circle " << i + 1 << ", closest point is: ";
		cout << "Point " << best_point + 1 << " (" << px[best_point] << ", " << py[best_point] << ")" << endl;
	}
	return 0;
}
