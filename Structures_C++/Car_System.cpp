/*Създайте структура Car, която съдържа:
brand – марка на автомобила
year – година на производство
price – цена
Да се напише програма, която:

1 Въвежда n автомобила (1 ≤ n ≤ 100)
2 Намира автомобила с най-ниска цена
3️ Намира най-стария автомобил
4 Извежда всички автомобили, произведени след 2015 г.
5️ Извежда всички автомобили с цена над средната
6️ Извежда броя на автомобилите, произведени преди 2000 г.*/

#include <iostream>
#include <string>
using namespace std;

struct Car {
	string brand;
	int year_of_manufacture;
	float price;
};

int main()
{
	Car cars[1000];

	int n;
	cout << "Enter a number of cars: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Write the brand: ";
		getline(cin, cars[i].brand);

		cout << "Year of manifacturing: ";
		cin >> cars[i].year_of_manufacture;

		cout << "Write the car price: ";
		cin >> cars[i].price;
	}

	int min_price_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (cars[i].price < cars[min_price_index].price)
			min_price_index = i;
	}

	int oldest_index = 0;
	{
		for (int i = 1; i < n; i++)
		{
			if (cars[i].year_of_manufacture < cars[oldest_index].year_of_manufacture)
				oldest_index = i;
		}
	}

	float sum_price = 0;
	for (int i = 0; i < n; i++)
		sum_price += cars[i].price;
	float average_price = sum_price / n;

	cout << "\nCars manufactured after 2015:\n";
	for (int i = 0; i < n; i++)
	{
		if (cars[i].year_of_manufacture > 2015)
			cout << cars[i].brand << endl;
	}

	cout << "\nCars with price above average (" << average_price << "):\n";
	for (int i = 0; i < n; i++)
	{
		if (cars[i].price > average_price)
			cout << cars[i].brand << endl;
	}

	int count_before_2000 = 0;
	for (int i = 0; i < n; i++)
	{
		if (cars[i].year_of_manufacture < 2000)
			count_before_2000++;
	}
	cout << "\nCar with lowest price: "
		<< cars[min_price_index].brand << " ("
		<< cars[min_price_index].price << ")\n";

	cout << "Oldest car: "
		<< cars[oldest_index].brand << " ("
		<< cars[oldest_index].year_of_manufacture << ")\n";

	cout << "Cars manufactured before 2000: "
		<< count_before_2000 << endl;

}
