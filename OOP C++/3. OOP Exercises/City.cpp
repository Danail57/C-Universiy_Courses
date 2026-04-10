/*Пешо обича да пътува и иска да записва в програма
градовете, които е посетил. За всеки град той пази:
Име на града (низ);
Държава (низ);
Оценка на преживяването (цяло число от 1 до 10).

Трябва да съставиш програма, която:
- Използва клас City, за да съхранява данните.
- Позволява на потребителя да добавя градове
в списък.
- Извежда всички посетени градове.
- Намира и извежда само градовете с оценка 
над 8 (любимите градове на Пешо). */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class City {
public:
	string city;
	string country;
	float rating;
	int visited_status;

	void get_data();
	void display() const;

	bool is_visited()
	{
		return visited_status != 0;
	}
};

void City::get_data()
{
	cin.ignore();
	cout << "City name: "; getline(cin, city);
	cout << "Country: "; cin >> country;
	cout << "Rating experience: "; cin >> rating;
	cout << "Visited? (1 - visited, 0 - not visited): "; cin >> visited_status;
}

void City::display() const
{
	cout << "City: " << city << "\n";
	cout << "Country: " << country << "\n";
	cout << "Rating: " << rating << "\n";
	cout << "Status: " << (visited_status ? "Visited" : "Not visited") << endl;
}


void display_data(const vector<City> towns)
{
	for (auto city : towns)
	{
		city.display();
	}
}


void display_favourite_cities(const vector<City> towns)
{
	bool found = false;
	for (auto city : towns)
	{
		if (city.rating > 8)
		{
			city.display();
			found = true;
		}
	}
	if (!found) cout << "No favourite cities found yet." << endl;
}


void display_all_visited_cities(const vector<City> towns)
{
	bool found = false;
	for (auto city : towns)
	{
		if (city.is_visited())
		{
			city.display();
			found = true;
		}
	}
	if (!found) cout << "No visited cities found." << endl;
}

int main()
{
	vector <City> diary;
	int choice;
	do {
		cout << "\nCity menu\n";
		cout << "1. Add city\n";
		cout << "2. Dispaly all data\n";
		cout << "3. Show favourite cities\n";
		cout << "4. Show all visited cities\n";
		cout << "5. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			City c;
			c.get_data();
			diary.push_back(c);
		}
		else if (choice == 2)
		{
			for (auto c : diary)
			{
				c.display();
			}
		}
		else if (choice == 3)
		{
			display_favourite_cities(diary);
		}
		else if (choice == 4)
		{
			display_all_visited_cities(diary);
		}
	} while (choice != 5);
}
