/*1.  Да се състави програма, която съхранява в масив
следната информация за лекарствата в една аптека:  
- наименование - низ до 20 знака; 
- цена - реално число; 
- налично количество - цяло число; 
- дата, до която е годно за употреба 
и извършва следните операции, избирани от меню:
- добавя към масива  данните на ново лекарство; 
- извежда всички въведени данни; 
- извежда имената на лекарствата с цена над 5 лв; 
- създава нов масив с данните на лекарствата
с налични количества под 10 броя;
- създава нов масив с имената количествата на
лекарствата с изтичащ срок на годност на зададена дата. */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Pharmacy {
public:
	string remedy_name;
	double price;
	int quantity_in_stock;
	string expiry_date;

	void get_data();
	void display() const;
};


void Pharmacy::get_data()
{
	cin.ignore();
	cout << "Name of the pill: "; getline(cin, remedy_name);
	cout << "Price per one: "; cin >> price;
	cout << "Quantity in stock: "; cin >> quantity_in_stock;
	cin.ignore();
	cout << "Expiry date: "; getline(cin, expiry_date);
}


void Pharmacy::display() const
{
	cout << "Remedy name: " << remedy_name << endl;
	cout << "Price: " << price << endl;
	cout << "In stock: " << quantity_in_stock << endl;
	cout << "Expiry date: " << expiry_date << endl;
}


void pills_above_5_euro(vector<Pharmacy> pills)
{
	cout << "Pills above 5 euro: " << endl;
	bool found = false;
	for (auto item: pills)
	{
		if (item.price > 5.0)
		{
			cout << item.remedy_name << endl;
			found = true;
		}
	}
	if (!found)
		cout << "No pills found in this price range." << endl;
}


vector<Pharmacy> quantity_below_10(vector<Pharmacy> pills)
{
	vector <Pharmacy> result;
	for (auto item : pills)
	{
		if (item.quantity_in_stock < 10)
		{
			result.push_back(item);
		}
	}
	return result;
}


vector<Pharmacy> check_expiry(vector<Pharmacy> pills, string current_date)
{
	vector<Pharmacy> result;
	for (auto item : pills)
	{
		if (item.expiry_date <= current_date)
		{
			result.push_back(item);
		}
	}	
	return result;
}


void diplay_all_medicines(vector<Pharmacy> pills)
{
	for (auto pill : pills)
		pill.display();
}

int main()
{
	vector<Pharmacy> pills;
	int choice;
	do {
		cout << "\nPharmacy menu\n";
		cout << "1. Add medicine\n";
		cout << "2. Show all medicines\n";
		cout << "3. Price > 5\n";
		cout << "4. Quantity < 10\n";
		cout << "5. Expiring by date\n";
		cout << "6. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			Pharmacy p;
			p.get_data();
			pills.push_back(p);
		}
		else if (choice == 2)
		{
			diplay_all_medicines(pills);
		}
		else if (choice == 3)
		{
			pills_above_5_euro(pills);
		}
		else if (choice == 4)
		{
			vector<Pharmacy> result = quantity_below_10(pills);
			diplay_all_medicines(result);
		}
		else if (choice == 5)
		{
			string date;
			cin.ignore();
			cout << "Enter date (YYYY-MM-DD): ";
			getline(cin, date);
			vector <Pharmacy> result = check_expiry(pills, date);
			diplay_all_medicines(result);
		}
	} while (choice != 6);
}
