/*2. Група делегати на национална конференция 
(име, ЕГН, населено място, пътни разходи) са 
настанени в няколко хотела ( име на хотела, 
номер на стаята, цена на нощувката). 
Всеки делегат получава делегатска карта с вписани: 
- делегатски номер (6 знака)
- дата на пристигане
- дата на отпътуване. 
Данните за всеки делегат, хотела, в който е настанен,
и неговата делегатска карта се съхраняват в масив.
Да се състави програма, която изпълнява от меню
следните операции:
- добавя към масива данните на нов делегат, 
делегатската му карта и хотела, в който е настанен;
- извежда всички въведени данни;
- намира сумата, която трябва да се заплати 
на посочен хотел за всички настанени там делегатки;
- извежда данните за делегат 
(име, ЕГН, населено място, пътни разходи) по
зададено ЕГН;
- създава масив с данните за 
делегатите - мъже (име, ЕГН, населено място, 
пътни разходи) , настанени в посочен хотел.*/

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

bool is_female(string EGN)
{
	if (EGN.length() < 10) return false;
	return !is_male(EGN);
}


class Person {
protected:
	string name, EGN, town;
	double travel_expenses;

public:
	virtual ~Person(){}
	virtual void get_data() = 0;
	virtual void display() = 0;

	virtual double get_female_hotel_cost(string h_name)
	{
		return 0;
	}

	virtual bool display_by_egn(string search_EGN)
	{
		return false;
	}

	virtual bool create_data_for_males_in_hotel(string target_hotel)
	{
		return false;
	}
};


class Delegate : public Person {
private:
	int delegate_number;
	string arrival_date;
	string departure_date;

public:
	string hotel_name;
	int room_number;
	double price_per_night;
	int nights;

	void get_data() override;
	void display() override;

	double get_female_hotel_cost(string h_name) override
	{
		if (hotel_name == h_name && is_female(EGN))
		{
			return price_per_night * nights;
		}
		return 0.0;
	}

	bool display_by_egn(string search_EGN) override
	{
		if (EGN == search_EGN)
		{
			cout << "Name: " << name << "| EGN: " << EGN << endl;
			return true;
		}
		return false;
	}
	bool create_data_for_males_in_hotel(string target_hotel) override
	{
		if (hotel_name == target_hotel && is_male(EGN))
		{
			cout << "Name: " << name << " | EGN: " 
				<< EGN << " | Town: " << town 
				<< " | Travel expenses: " 
				<< travel_expenses << " euro" << endl;
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
	cout << "Hotel room: "; cin >> room_number;
	cin.ignore();
	cout << "Hotel name: "; getline(cin, hotel_name);
	cout << "Price per night: "; cin >> price_per_night;
	cout << "Number of nights: "; cin >> nights;
	cout << "Arrival date (YYYY/MM/DD): "; cin >> arrival_date;
	cout << "Departure date (YYYY/MM/DD): "; cin >> departure_date;
}

void Delegate::display()
{
	cout << "Name: " << name << " | EGN: " << EGN << "| Town: " << town << endl;
	cout << "Travel expenses: " << travel_expenses << endl;
	cout << "Delegate number: " << delegate_number << endl;
	cout << "Hotel: " << hotel_name << "| Room: " << room_number << "| Price per Night: " << price_per_night << endl;
	cout << "Arrival: " << arrival_date << "| Departure: " << departure_date << "| Nights: " << nights << endl;
}


void display_all_data(vector<Person*> delegate)
{
	for (Person* p : delegate)
	{
		p->display();
	}
}

double calculate_female_hotel_sum(vector<Person*> delegates, string search_hotel)
{
	double total_sum = 0;
	for (Person* p : delegates)
	{
		total_sum += p->get_female_hotel_cost(search_hotel);
	}
	return total_sum;
}

void find_delegate_by_egn(vector<Person*> delegates, string search_EGN)
{
	bool found = false;
	for (Person* p : delegates)
	{
		if (p->display_by_egn(search_EGN))
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Delegate with EGN " << search_EGN << " was not found.\n";
	}
}

void filter_males_by_hotel(vector<Person*> delegates, string target_hotel)
{
	vector<Person*> male_hotel_array;
	for (auto d : delegates)
	{
		if (d->create_data_for_males_in_hotel(target_hotel))
		{
			male_hotel_array.push_back(d);
		}
	}

	if (male_hotel_array.empty())
	{
		cout << "No male delegates found in this hotel.\n";
	}
	else
	{
		cout << "\n(Successfully created a new array with " << male_hotel_array.size() << " male delegates.)\n";
	}
	male_hotel_array.clear();
}

int main()
{
	vector<Person*> delegates;
	int choice;
	do {
		cout << "\nMENU\n";
		cout << "1. Add new delegate\n";
		cout << "2. Display all data\n";
		cout << "3. Calculate hotel cost for female delegates\n";
		cout << "4. Find delegate basic data by EGN\n";
		cout << "5. Create male delegates array for specific hotel\n";
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
			string search_hotel;
			cin.ignore();
			cout << "Write the hotel name: "; getline(cin, search_hotel);
			double result = calculate_female_hotel_sum(delegates, search_hotel);
			cout << "Total sum to pay for female delegates: " << result << " BGN" << endl;
		}
		else if (choice == 4)
		{
			string search_egn;
			cout << "Enter EGN to search: "; cin >> search_egn;
			find_delegate_by_egn(delegates, search_egn);
		}
		else if (choice == 5)
		{
			string target_hotel;
			cin.ignore();
			cout << "Write hotel to filter: "; getline(cin, target_hotel);
			filter_males_by_hotel(delegates, target_hotel);
		}

	} while (choice != 6);
	for (Person* p : delegates)
	{
		delete p;
	}
	delegates.clear();
}
