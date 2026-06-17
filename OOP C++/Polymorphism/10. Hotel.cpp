/*6. Да се състави програма за нуждите на хотел,
която поддържа в масив следната информация 
за гостите на хотела:
- име - низ до 20 знака;
- ЕГН - низ от 10 знака;
- семейно положение (1-несемеен, 2-семеен);
- брой нощувки - цяло число;
- цена на ползваното легло - реално число;
- населено място - низ до 25; знака

и извършва следните операции, избирани от меню:
- записва в едномерен масив въведените данни;
- извежда на екрана всички въведени данни;
- извежда на екрана имената и заплатената сума
от семейните гости от зададено населено място;
- създава нов масив с данните на несемейните 
мъже, родени през посочена година
- създава нов масив с данните на несемейните
гости от посочено населено място.
- извежда на екрана имената и заплатената сума 
от семейните гости, пребивавали повече от 5 дни.
- извежда на екрана имената и заплатената сума от
несемейните гости от посочено населено място;
- създава нов масив с данните на семейните гости,
заплатили над 50 лева за нощувка
- извежда на екрана имената и заплатената сума от несемейните гости, 
родени през посочен месец;
- създава нов масив с данните на несемейните жени 
от посочено населено място, заплатили над 100 лева
- извежда на екрана имената и тел.номера на жените,
родени през посочена година
- създава нов масив с данните на клиентите мъже,
кандидати за посочена страна.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_female(string EGN)
{
	if (EGN.length() < 10) return false;
	int gender_digit = EGN[8] - '0';
	return (gender_digit % 2 != 0);
}

bool is_male(string EGN)
{
	if (EGN.length() < 10) return false;
	int gender_digit = EGN[8] - '0';
	return (gender_digit % 2 == 0);
}


int get_birth_year(string EGN)
{
	int year = stoi(EGN.substr(0, 2));
	int month = stoi(EGN.substr(2, 2));

	if (month > 40)
	{
		year += 2000;
	}

	else if (month > 20)
	{
		year += 1800;
	}

	else
	{
		year += 1900;
	}
	return year;
}

int get_birth_month(string EGN)
{
	int month = stoi(EGN.substr(2, 2));

	if (month > 40)
		month -= 40;
	else if (month > 20)
		month -= 20;

	return month;
}


class Hotel {
public:
	string name;
	string EGN;
	int marital_status;
	double price;
	string town;
	int days;
	string phone;

	void get_data();
	void display();
};

void Hotel::get_data()
{
	cin.ignore();
	cout << "Guest name: "; getline(cin, name);
	cout << "EGN: "; cin >> EGN;
	cout << "Marital status: (1 - single, 2 - married): "; cin >> marital_status;
	cout << "Price: "; cin >> price;
	cout << "Days in hotel: "; cin >> days;
	cout << "Town: "; cin >> town;
	cout << "Phone: "; cin >> phone;
}

void Hotel::display()
{
	cout << "Guest name: " << name << endl;
	cout << "EGN: " << EGN << endl;
	cout << "Marital status: " << marital_status << endl;
	cout << "Price: " << price << endl;
	cout << "Days: " << days << endl;
	cout << "Town: " << town << endl;
	cout << "Phone: " << phone << endl;
}

void display_all_data(vector<Hotel> guests)
{
	for (auto guest : guests)
	{
		guest.display();
	}
}

// извежда на екрана имената и заплатената сума
// от семейните гости от зададено населено място
void display_married_from_town(vector<Hotel> guests, string town)
{
	for (auto guest : guests)
	{
		if (guest.marital_status == 2 && guest.town == town)
		{
			cout << "Guest name: " << guest.name << endl;
			cout << "Paid sum: " << guest.price << endl;
			cout << endl;
		}
	}
}



// създава нов масив с данните на несемейните
// мъже, родени през посочена година
vector<Hotel> unmarried_men_born_in_year(vector<Hotel> guests, int year)
{
	vector<Hotel> result;
	for (auto guest : guests)
	{
		if (guest.marital_status == 1 && get_birth_year(guest.EGN) == year && is_male(guest.EGN))
		{
			result.push_back(guest);
		}
	}
	return result;
}


// създава нов масив с данните на несемейните
// гости от посочено населено място
vector<Hotel> unmarried_guests_from_town(vector<Hotel> guests, string town)
{
	vector<Hotel> result;
	for (auto guest : guests)
	{
		if (guest.marital_status == 1 && guest.town == town)
		{
			result.push_back(guest);
		}
	}
	return result;
}

// извежда на екрана имената и заплатената сума
// от семейните гости, пребивавали повече от 5 дни

void display_married_guests_for_5_days(vector<Hotel> guests)
{
	for (auto guest : guests)
	{
		if (guest.marital_status == 2 && guest.days > 5)
		{
			cout << "Guest name: " << guest.name << endl;
			cout << "Paid price: " << guest.price << endl;
			cout << endl;
		}
	}
}

// извежда на екрана имената и заплатената сума от
// несемейните гости от посочено населено място

void display_names_and_paid_sum_for_unmarried_guests_from_town(vector<Hotel> guests, string town)
{
	for (auto guest : guests)
	{
		if (guest.marital_status == 1 && guest.town == town)
		{
			cout << "Guest name: " << guest.name << endl;
			cout << "Paid price: " << guest.price << endl;
			cout << endl;
		}
	}
}

// създава нов масив с данните на семейните гости,
// заплатили над 50 лева за нощувка
vector<Hotel> married_guests_paid_50lv_for_night(vector<Hotel> guests)
{
	vector<Hotel> result;
	for (auto guest : guests)
	{
		if (guest.price > 50 and guest.marital_status == 2)
		{
			result.push_back(guest);
		}
	}
	return result;
}



// извежда на екрана имената и заплатената сума
// от несемейните гости, родени през посочен месец
void display_unmarried_guests_born_in_month(vector<Hotel> guests, int month)
{
	for (auto guest : guests)
	{
		if (guest.marital_status == 1 &&
			get_birth_month(guest.EGN) == month)
		{
			cout << "Guest name: " << guest.name << endl;
			cout << "Paid price: " << guest.price << endl;
		}
	}
}

// създава нов масив с данните на несемейните жени
// от посочено населено място, заплатили над 100 лева
vector<Hotel> unmarried_females_from_town_paid_up_100lv(vector<Hotel> guests, string town)
{
	vector<Hotel> result;
	for (auto guest : guests)
	{
		if (guest.marital_status == 1 && is_female(guest.EGN) && guest.town == town && guest.price > 100.0)
		{
			result.push_back(guest);
		}
	}
	return result;
}

// извежда на екрана имената и тел.номера на
// жените, родени през посочена година
void display_females_born_in_year_and_phones(vector<Hotel> guests, int year)
{
	for (auto guest : guests)
	{
		if (is_female(guest.EGN) &&
			get_birth_year(guest.EGN) == year)
		{
			cout << "Name: " << guest.name << endl;
			cout << "Phone: " << guest.phone << endl;
			cout << endl;
		}
	}
}

int main()
{
	vector<Hotel> guests;
	int choice;

	do {
		cout << "\nPREMIUM HOTEL MENU\n";
		cout << "1. Add guest\n";
		cout << "2. Display all data\n";
		cout << "3. Display married from town\n";
		cout << "4. Display unmarried men born in year\n";
		cout << "5. Display unmarried guests from town\n";
		cout << "6. Display married guests for 5_days\n";
		cout << "7. Display names and paid sum for unmarried guests from town\n";
		cout << "8. married guests paid 50lv for night\n";
		cout << "9. Display unmarried guests born in month\n";
		cout << "10. Display unmarried females from town paid up 100lv\n";
		cout << "11. Display females born in year and phones\n";
		cout << "12. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			Hotel guest;
			guest.get_data();
			guests.push_back(guest);
		}
		else if (choice == 2)
		{
			display_all_data(guests);
		}
		else if (choice == 3)
		{
			string town;
			cout << "Write town: ";
			getline(cin, town);
			display_married_from_town(guests, town);
		}
		else if (choice == 4)
		{
			int year;
			cout << "Write birth year: ";
			cin >> year;

			vector<Hotel> result = unmarried_men_born_in_year(guests, year);
			display_all_data(result);
		}
		else if (choice == 5)
		{
			string town;
			cout << "Town: ";
			getline(cin, town);
			vector <Hotel> result = unmarried_guests_from_town(guests, town);
			display_all_data(result);
		}
		else if (choice == 6)
		{
			display_married_guests_for_5_days(guests);
		}
		else if (choice == 7)
		{
			string town;
			cout << "Town: ";
			cin >> town;

			display_names_and_paid_sum_for_unmarried_guests_from_town(guests, town);
		}
		else if (choice == 8)
		{
			vector<Hotel> result = married_guests_paid_50lv_for_night(guests);

			display_all_data(result);
		}
		else if (choice == 9)
		{
			int month;
			cout << "Month: ";
			cin >> month;

			display_unmarried_guests_born_in_month(guests, month);
		}
		else if (choice == 10)
		{
			string town;
			cout << "Town: ";
			getline(cin, town);

			vector<Hotel> result = unmarried_females_from_town_paid_up_100lv(guests, town);
			display_all_data(result);
		}
		else if (choice == 11)
		{
			int year;
			cout << "Year: ";
			cin >> year;

			display_females_born_in_year_and_phones(guests, year);
		}

	} while (choice != 12);
}
