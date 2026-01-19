/*Стрелец произвежда изстрели по показаната мишена
(фиг. 1) докато събере N точки или произведе
М изстрела. За попадение в област 1 - кръг
се дават 10 точки, а в област 2 - квадрат – 5 точки.
Да се състави алгоритъм, който извежда
броя на произведените изстрели и броя на събраните 
точки. */

#include <iostream>
using namespace std;


int main()
{
	int M, N, R;
	double x, y, a;
	int points = 0;
	int shots = 0;

	cout << "Enter the number of shots: ";
	cin >> M;

	cout << "Enter the radius: ";
	cin >> R;

	cout << "Enter the needed points: ";
	cin >> N;

	cout << "Enter the half side of the square: ";
	cin >> a;

	while (M > shots && N > points)
	{
		cout << "Shoot... (x y): ";
		cin >> x >> y;
		shots++;

		if (x * x + y * y <= R * R)
		{
			points += 10;
		}
		else if (abs(x) <= a && abs(y) <= a)
		{
			points += 5;
		}
	}
	cout << "Shots made: " << shots << endl;
	cout << "Points collected: " << points << endl;
}
