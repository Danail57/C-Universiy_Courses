/*3. Група делегати на национална конференция
(име, ЕГН, населено място, пътни разходи) 
са настанени в няколко хотела ( име на хотела, 
номер на стаята, цена на нощувката). Всеки делегат
получава делегатска карта с вписани: 
- делегатски номер (6 знака), 
- дата на пристигане, 
- дата на отпътуване. 
Данните за всеки делегат, хотела, в който е 
настанен, и неговата делегатска карта се съхраняват в масив.
Да се състави програма, която изпълнява от
меню следните операции:
- добавя към масива данните на нов делегат,
делегатската му карта и хотела, в който е настанен;
- извежда всички въведени данни;
- извежда сумарните пътни разходи за делегатите
от посочено населено място;
- извежда данните на делегатката 
(име, ЕГН, населено място, пътни разходи) 
с най-големи пътни разходи;
- създава масив с данните за делегатите-мъже 
(име, ЕГН, населено място, пътни разходи), 
родени през посочена година*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_male(string EGN)
{
	if (EGN.length() < 10)
	{
		return false;
	}
	int gender_digit = EGN[8] - '0';
	return (gender_digit % 2 == 0);
}

bool is_female(string EGN)
{
	if (EGN.length() < 10) return false;
	return !is_male(EGN);
}


int get_birth_year(string EGN)
{
	if (EGN.length() < 10) return 0;

	int year_short = stoi(EGN.substr(0, 2));
	int month = stoi(EGN.substr(2, 2));

	if (month >= 1 && month <= 12) return 1900 + year_short;
	if (month >= 41 && month <= 52) return 2000 + year_short;
	if (month >= 21 && month <= 32) return 1800 + year_short;
	return 1900 + year_short;
}

class Person {
protected:
	string name, EGN, town;
	double travel_expenses;

public:
	virtual ~Person(){}
	virtual void get_data() = 0;
	virtual void display() = 0;

	virtual double get_all_delegates_travel_expenses_from_city(string target_town)
	{
		return 0;
	}

	virtual bool show_women_delegate_with_the_most_travel_expenses(double expenses, string EGN)
	{
		return false;
	}

	virtual bool create_array_with_men_born_on_a_year(int target_year)
	{
		return false;
	}

	virtual string get_egn() 
	{
		return EGN;
	}

	virtual double get_travel_expenses() 
	{
		return travel_expenses;
	}
	virtual string get_name() const {
		return name;
	}
	virtual string get_town() const {
		return town;
	}
};


class Delegate : public Person {
private:
	int delegate_number;
	string arrival_date, departure_date;
public:
	string hotel_name;
	int room_number;
	double price_per_night;
	int nights;

	void get_data() override;
	void display() override;

	double get_all_delegates_travel_expenses_from_city(string target_town) override
	{
		if (town == target_town)
		{
			return travel_expenses;
		}
		return 0.0;
	}

	bool create_array_with_men_born_on_a_year(int target_year) override
	{
		if (is_male(EGN) && get_birth_year(EGN) == target_year)
		{
			cout << "Name: " << name << " | EGN: " << EGN
				<< " | Town: " << town << " | Travel expenses: " << travel_expenses << " BGN" << endl;
			return true;
		}
		return false;
	}

	bool show_women_delegate_with_the_most_travel_expenses(double expenses, string EGN) override
	{
		if (is_female(this->EGN))
		{
			if (travel_expenses > expenses)
			{
				return true;
			}
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
	cout << "Delegate number (6 characters): "; cin >> delegate_number;
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
	cout << "Name: " << name << " | EGN: " << EGN << " | Town: " << town << endl;
	cout << "Travel expenses: " << travel_expenses << " BGN" << endl;
	cout << "Delegate card: " << delegate_number << " | Dates: " << arrival_date << " to " << departure_date << endl;
	cout << "Hotel: " << hotel_name << " | Room: " << room_number << " | Price/Night: " << price_per_night << " BGN (" << nights << " nights)" << endl;
}

void display_all_data(vector<Person*> delegates)
{
	if (delegates.empty())
	{
		cout << "No delegates registered yet.\n";
		return;
	}

	for (Person* p : delegates)
	{
		p->display();
	}
}

void calculate_expenses_for_town(vector<Person*>& delegates, string search_town)
{
	double total_sum = 0;
	for (Person* p : delegates)
	{
		total_sum += p->get_all_delegates_travel_expenses_from_city(search_town);
	}
	cout << "Total travel expenses for delegates from " << search_town << ": " << total_sum << " euro" << endl;
}

void filter_males_by_year(vector<Person*>& delegates, int target_year)
{
	vector<Person*> male_year_array;
	for (Person* p : delegates)
	{
		if (p->create_array_with_men_born_on_a_year(target_year))
		{
			male_year_array.push_back(p);
		}
	}

	if (male_year_array.empty())
	{
		cout << "No male delegates found born in this year.\n";
	}
	else
	{
		cout << "\n(Successfully created a new array with " << male_year_array.size() << " male delegates.)\n";
	}
	male_year_array.clear();
}

void find_max_expenses_female(const vector<Person*>& delegates)
{
	double max_expenses = -1.0;
	bool found_any_female = false;
	for (Person* p : delegates)
	{
		if (p->show_women_delegate_with_the_most_travel_expenses(max_expenses, ""))
		{
			max_expenses = p->get_travel_expenses();
			found_any_female = true;
		}
	}
	if (found_any_female)
	{
		for (Person* p : delegates)
		{
			if (is_female(p->get_egn()) && p->get_travel_expenses() == max_expenses)
			{
				cout << "Name: " << p->get_name() << endl;
				cout << "EGN: " << p->get_egn() << endl;
				cout << "Town: " << p->get_town() << endl;
				cout << "Travel expenses: " << p->get_travel_expenses() << " euro" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "No female delegates found.\n";
	}
}


int main()
{
	vector<Person*> delegates;
	int choice;
	do {
		cout << "\nMENU\n";
		cout << "1. Add new delegate\n";
		cout << "2. Display all data\n";
		cout << "3. Total travel expenses by town\n";
		cout << "4. Find female delegate with max travel expenses\n";
		cout << "5. Create male delegates array by birth year\n";
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
			string search_town;
			cin.ignore();
			cout << "Enter town name: "; getline(cin, search_town);
			calculate_expenses_for_town(delegates, search_town);
		}
		else if (choice == 4)
		{
			find_max_expenses_female(delegates);
		}
		else if (choice == 5)
		{
			int year;
			cout << "Enter birth year (e.g. 1995): "; cin >> year;
			filter_males_by_year(delegates, year);
		}

	} while (choice != 6);

	for (Person* p : delegates)
	{
		delete p;
	}
	delegates.clear();
}
