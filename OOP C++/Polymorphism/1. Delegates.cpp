/*1. Група делегати на национална конференция
(име, ЕГН, населено място, пътни разходи) 
са настанени в няколко хотела (име на хотела, 
номер на стаята, цена на нощувката).
Всеки делегат получава делегатска карта с вписани :
- делегатски номер (6 знака), 
- дата на пристигане, 
- дата на отпътуване.
Данните за всеки делегат, хотела, в който е настанен,
и неговата делегатска карта се съхраняват в масив.

Да се състави програма, която изпълнява 
от меню следните операции:
-добавя към масива данните на нов делегат,
делегатската му карта и хотела, в който е настанен;
-извежда всички въведени данни;
-намира сумата, която трябва да 
се заплати на посочен хотел за нощувките
на делегатите от зададено населено място;
-извежда името на най - рано пристигналия
делегат мъж и данните за хотела, в който е настанен;
-създава масив с данните за делегатите
(име, ЕГН, населено място, пътни разходи) 
от посочено населено място */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_male(string EGN)
{
	if (EGN.length() < 10) return false;
	int gender_digit = EGN[8] - '0';
	return (gender_digit % 2 == 0);
}

class Person {
protected:
	string name;
	string EGN;
	string town;
	double travel_expenses;

public:
	virtual ~Person(){}
	virtual void get_data() = 0;
	virtual void display() = 0;

	// поведението на производните класове,
	// пренаписваме го чрез override
	virtual double get_hotel_cost_if_matches(string h_name, string t_name)
	{
		return 0;
	}

	virtual string get_arrival_date()
	{
		return "";
	}

	virtual bool early_arrived_male(string& current_earliest_date)
	{
		return false;
	}

	virtual bool is_male_delegate()
	{
		return false;
	}

	virtual bool create_data_for_delegates_from_a_town(string target_town) { return false; }
	virtual void display_hotel_only(){}
	virtual bool is_from_a_town(string t_name) { return false; }
};

class Delegate : public Person {
private:
	int delegate_number;
	int hotel_room;
	string hotel_name;
	double night_price;
	int nights;

public:
	string date_arrival;
	string departure_date;
	void get_data() override;
	void display() override;

	double get_hotel_cost_if_matches(string h_name, string t_name) override
	{
		if (hotel_name == h_name && town == t_name)
		{
			return night_price * nights;
		}
		return 0;
	}

	bool early_arrived_male(string& current_earliest_date) override
	{
		if (is_male(EGN) && date_arrival < current_earliest_date)
		{
			current_earliest_date = date_arrival;
			return true;
		}
		return false;
	}

	string get_arrival_date() override
	{
		return date_arrival;
	}

	bool is_male_delegate() override
	{
		return is_male(EGN);
	}

	void display_hotel_only() override
	{
		cout << "\nEarliest arrived male delegate: " << name << endl;
		cout << "Hotel: " << hotel_name << " | Room: " << hotel_room << endl;
	}

	bool is_from_a_town(string t_name) override
	{
		return (town == t_name);
	}

	bool create_data_for_delegates_from_a_town(string target_town) override
	{
		if (town == target_town)
		{
			cout << "Name: " << name << " | EGN: " << EGN << " | Town: " << town << " | Travel expenses: " << travel_expenses << " BGN" << endl;
			return true;

		}
		return false;
	}
};


void Delegate::get_data()
{
	cin.ignore();
	cout << "Name: "; getline(cin, name);
	cout << "EGN: "; cin >> EGN;
	cin.ignore();
	cout << "Town: "; getline(cin, town);
	cout << "Travel expenses: "; cin >> travel_expenses;
	cout << "Delegate number: "; cin >> delegate_number;
	cout << "Hotel room: "; cin >> hotel_room;
	cin.ignore();
	cout << "Hotel name: "; getline(cin, hotel_name);
	cout << "Price per night: "; cin >> night_price;
	cout << "Number of nights: "; cin >> nights;
	cout << "Arrival date (YYYYMMDD): "; cin >> date_arrival;
	cout << "Departure date (YYYYMMDD): "; cin >> departure_date;
}

void Delegate::display()
{
	cout << "Name: " << name << " | EGN: " << EGN << "| Town: " << town << endl;
	cout << "Travel expenses: " << travel_expenses << endl;
	cout << "Delegate number: " << delegate_number << endl;
	cout << "Hotel: " << hotel_name << "| Room: " << hotel_room << "| Price per Night: " << night_price << endl;
	cout << "Arrival: " << date_arrival << "| Departure: " << departure_date << "| Nights: " << nights << endl;
}


void display_all_data(vector<Person*> people)
{
	for (Person* p : people)
	{
		p->display();
	}
}

double calculate_total_hotel_sum(vector <Person*> people, string search_hotel, string search_town)
{
	double total_sum = 0;
	for (Person* p : people)
	{
		total_sum += p->get_hotel_cost_if_matches(search_hotel, search_town);
	}
	return total_sum;
}

void print_earliest_man_and_hotel(vector<Person*> people)
{
	string min_date = "99999999"; // трик за намиране на минимум.
	int best_index = -1;
	bool found = false;

	for (int i = 0; i < people.size(); i++)
	{
		if (people[i]->early_arrived_male(min_date))
		{
			best_index = i;
			found = true;
		}
	}
	if (found && best_index != -1)
	{
		people[best_index]->display_hotel_only();
	}
	else
	{
		cout << "\nNo male delegates found.\n";
	}
}


void filter_from_town(vector<Person*> delegates, string target_town)
{
	vector <Person*> town_array;
	for (auto d : delegates)
	{
		if (d->create_data_for_delegates_from_a_town(target_town))
		{
			town_array.push_back(d);
		}
	}
	if (town_array.empty())
	{
		cout << "No delegates found from " << target_town << ".\n";
	}
	else
	{
		cout << "(Successfully created a new array with " << town_array.size() << " delegates from " << target_town << ".)\n";
	}
	town_array.clear();
}

int main()
{
	vector <Person*> delegates;
	int choice;
	do {
		cout << "\nDELEGATE MENU\n";
		cout << "1. Add new delegate\n";
		cout << "2. Display all data\n";
		cout << "3. Calculate hotel cost for specific town\n";
		cout << "4. Find earliest arrived male delegate\n";
		cout << "5. Create basic data array for town\n";
		cout << "6. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			Person* p = new Delegate();
			p->get_data();
			delegates.push_back(p);
		}
		else if (choice == 2)
		{
			display_all_data(delegates);
		}
		else if (choice == 3)
		{
			string search_hotel, search_town;
			cin.ignore();
			cout << "Write the hotel name: "; getline(cin, search_hotel);
			cout << "Write the city: "; getline(cin, search_town);
			double result = calculate_total_hotel_sum(delegates, search_hotel, search_town);
			cout << "Total sum to pay: " << result << " euro" << endl;
		}
		else if (choice == 4)
		{
			print_earliest_man_and_hotel(delegates);
		}
		else if (choice == 5)
		{
			string target_town;
			cin.ignore();
			cout << "Write town to filter: "; getline(cin, target_town);
			filter_from_town(delegates, target_town);
		}
	} while (choice != 6);
	for (Person* p : delegates)
	{
		delete p;
	}
	delegates.clear();
}
