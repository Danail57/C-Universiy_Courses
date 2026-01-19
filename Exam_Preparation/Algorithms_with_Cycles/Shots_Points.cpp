/*Стрелец произвежда N изстрели по показаната 
мишена (фиг. 2). 
Да се състави алгоритъм, който извежда
процента на попаденията в област 1 - квадрата, 
в област 2 - кръга и извън мишената. */

#include <iostream>
using namespace std;


int main()
{
	int N;
	double x, y;
	double R, a;

	int count1 = 0;
	int count2 = 0;
	int count_out = 0;

	cout << "Enter number of shots: ";
	cin >> N;

	cout << "Enter the radius: ";
	cin >> R;
	
	cout << "Enter half side of square a: ";
	cin >> a;

	for (int i = 0; i < N; i++)
	{
		cout << "Shot " << i + 1 << " (x y): ";
		cin >> x >> y;

		if (abs(x) <= a && abs(y) <= a)
		{
			count1++;
		}
		else if (x * x + y * y <= R * R)
		{
			count2++;
		}
		else
		{
			count_out++;
		}
	}
	cout << "\nResults:\n";
	cout << "Area 1 (square): " << count1 * 100.0 / N << " %\n";
	cout << "Area 2 (circle): " << count2 * 100.0 / N << " %\n";
	cout << "Outside target: " << count_out * 100.0 / N << " %\n";
}
