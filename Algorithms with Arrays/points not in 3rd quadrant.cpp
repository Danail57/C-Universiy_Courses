/*7) Дадени са два масива x и y, които съдържат
координатите на k точки в равнината. 
Да се намерят броя на точките, които не лежат в
трети квадрант и номера на тази, която е
най-отдалечена от абсцисната ос.*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int k;
	cout << "Enter the number of points: ";
	cin >> k;

	int x[1000], y[1000];
	for (int i = 0; i < k; i++)
	{
		cout << "Point[" << i + 1 << "] = ";

		cout << "x[" << i + 1 << "] = ";
		cin >> x[i];

		cout << "y[" << i + 1 << "] = ";
		cin >> y[i];
	}

	int count_not_third = 0;
	int index_farthest = -1;
	double max_distance = -1;

	for (int i = 0; i < k; i++)
	{
		if (!(x[i] < 0 && y[i] < 0))
		{
			count_not_third++;
			double distance = fabs(y[i]);
			if (distance > max_distance)
			{
				max_distance = distance;
				index_farthest = i;
			}
		}
	}
	cout << "Number of points not in 3rd quadrant: " << count_not_third << endl;
	if (index_farthest != -1)
		cout << "Point farthest from x-axis is number: " << index_farthest + 1 << " with coordinates (" << x[index_farthest] << ", " << y[index_farthest] << ")" << endl;
	return 0;
}
