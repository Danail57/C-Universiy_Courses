/*9. Да се състави програма за нуждите на хотел, 
която поддържа в масив следната информация за гостите
на хотела: 
име - низ до 20 знака; 
ЕГН - низ от 10 знака; 
семейно положение (1-несемеен, 2-семеен);
брой нощувки - цяло число;
цена на ползваното легло - реално число; 
населено място - низ до 25 знака
и извършва следните операции, избирани от меню:
- записва в едномерен масив въведените данни; 
- извежда на екрана всички въведени данни;
- извежда на екрана имената и заплатената сума 
от несемейните гости, родени през посочен месец;
- създава нов масив с данните на несемейните жени от
посочено населено място, заплатили над 100 лева   */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hotel {
public:
	string name;
	string egn;
	int marital_status;
	int nights;
	double price;
	string city;

	void get_data();
	void display() const;
};

void Hotel::get_data()
{
	cin.ignore();
	cout << "Guest name: "; getline(cin, name);
	cout << "EGN: "; cin >> egn;
	cout << "Marital status: (1 - single; 2 - family): "; cin >> marital_status;
	cout << "Nights: "; cin >> nights;
	cout << "Price: "; cin >> price;
	cin.ignore();
	cout << "Residence city: "; getline(cin, city);
}

void Hotel::display() const
{
	cout << "Guest name: " << name << endl;
	cout << "EGN: " << egn << endl;
	cout << "Marital status: " << marital_status << endl;
	cout << "Nights: " << nights << endl;
	cout << "Price: " << price << endl;
	cout << "Residence city: " << city << endl;
}

bool is_female(string egn)
{
	if (egn.length() < 10) return false;
	int gender_digit = egn[8] - '0';
	return (gender_digit % 2 != 0);
}

void display_all_data(const vector<Hotel>& guests)
{
	for (auto guest:guests)
	{
		guest.display();
	}
}

vector<Hotel> single_women_paid_over_100(const vector<Hotel> single_women_guests, double price, string target_city)
{
	vector<Hotel> result;
	for (auto guest: single_women_guests)
	{
		double total_paid = guest.nights * guest.price;
		if (guest.marital_status == 1 && is_female(guest.egn)&&
			total_paid > 100.0 &&
			guest.city == target_city)
		{
			result.push_back(guest);
		}
	}
	return result;
}

int get_month_from_egn(string egn)
{
	int month = stoi(egn.substr(2, 2));
	if (month > 40) month -= 40;
	else if (month > 20) month -= 20;
	return month;
}

void display_single_by_month(const vector <Hotel> guests, int target_month)
{
	bool found = false;
	for (auto guest : guests)
	{
		if (guest.marital_status == 1)
		{
			if (get_month_from_egn(guest.egn) == target_month)
			{
				double total_sum = guest.nights * guest.price;
				cout << "Name: " << guest.name << " | Sum: " << total_sum << endl;
				found = true;
			}
		}
	}
	if (!found)
	{
		cout << "No matches" << endl;
	}
}


int main()
{
	vector<Hotel> guests;
	int choice;

	do {
		cout << "\nHotel menu\n";
		cout << "1. Add guest\n";
		cout << "2. Dsiplay all data\n";
		cout << "3. Display names and sums of single guests by birth month\n";
		cout << "4. Create list of single women from city with total > 100\n";
		cout << "5. Exit\n";
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
			int month;
			cout << "Enter month (1-12): ";
			cin >> month;
			display_single_by_month(guests, month);
		}
		else if (choice == 4)
		{
			string target_city;
			cin.ignore();
			cout << "Write a city: ";
			getline(cin, target_city);

			vector <Hotel> filtered;
			for (auto guest : guests)
			{
				double total = guest.nights * guest.price;
				if (guest.marital_status == 1 && is_female(guest.egn) && guest.city == target_city && total > 100.0)
				{
					filtered.push_back(guest);
				}
			}
			cout << "Filtered result\n";
			if (filtered.empty()) cout << "No matches";
			else display_all_data(filtered);
		}
	} while (choice != 5);
}
