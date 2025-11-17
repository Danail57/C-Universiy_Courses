// Зададени са координатите x,y на N точки в 
// равнината. Точките последователно са съединени с 
// отсечки. 
// Да се намери дължината на начупената линия.


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int N;
	cout << "Enter the number of points: ";
	cin >> N;

	while (true)
	{
		if (!cin || N < 2) // тук правим тази проверка, 
			// за да се уверим, че точно две 
			// точки са въведени, тъй като така
			// се образува отсечка
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input for N. Enter a whole number >= 2.\n";
			continue;
		}
		break;
	}

	double x[1000], y[1000];

	// Entering the coordinates
	for (int i = 0; i < N; i++)
	{
		while (true)
		{
			cout << "Enter the coordinates for point " << i + 1 << "(x y): ";
			cin >> x[i] >> y[i];
			if (!cin)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input! Enter numbers!\n";
				continue;
			}
			break;
		}
	}
	// Evaluating the length
	double length = 0;
	for (int i = 1; i < N; i++)
	{
		double dx = x[i] - x[i - 1];
		double dy = y[i] - y[i - 1];
		cout << fixed << setprecision(2);
		length += sqrt(dx * dx + dy * dy);
	}

	cout << "The total length of the broken line is: " << length << endl;
	return 0;

}
