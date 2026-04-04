/*2. Да се състави програма, която съхранява в масив
следната информация за лекарствата в една аптека: 
- наименование - низ до 20 знака; 
- цена - реално число;
- налично количество - цяло число; 
- дата, до която е годно за употреба 
и извършва следните операции, избирани от меню: 
- добавя към масива данните на ново лекарство; 
- извежда всички въведени данни; 
- извежда общата стойност на лекарствата в аптеката
с цена над 10 лв.; 
- създава нов масив с данните на лекарствата с цена над 15 лв; 
- създава нов масив с имената и цените на лекарствата
с изтичащ срок на годност на зададена дата.  */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pharmacy {
public:
	string medicine_name;
	double price;
	int quantity;
	string expiry_date;

	void get_data();
	void display() const;
};

void Pharmacy::get_data()
{
	cin.ignore();
	cout << "Medicine name: "; getline(cin, medicine_name);
	cout << "Price: "; cin >> price;
	cout << "Quantity: "; cin >> quantity;
	cin.ignore();
	cout << "Date of expiry: (YYYY-MM-DD)"; getline(cin, expiry_date);
}

void Pharmacy::display() const
{
	cout << "Medicine name: " << medicine_name << endl;
	cout << "Price: " << price << endl;
	cout << "In stock: " << quantity << endl;
	cout << "Expiry date: " << expiry_date << endl;
}

void display_all_medicines(const vector<Pharmacy>& pills)
{
	for (auto pill : pills)
		pill.display();
}

void check_expiry_date(const vector<Pharmacy>& pills, string current_date)
{
	vector<Pharmacy> result;
	for (auto item : pills)
	{
		if (item.expiry_date <= current_date)
		{
			cout << item.medicine_name << " - " << item.price << endl;
		}
	}
}

vector<Pharmacy> price_up_15(const vector<Pharmacy>& pills)
{
	vector<Pharmacy> result;
	for (auto item : pills)
	{
		if (item.price > 15.0)
		{
			result.push_back(item);
		}
	}
	return result;
}

double total_price_pills_above_10(const vector<Pharmacy>& pills)
{
	double sum = 0;
	for (auto pill : pills)
	{
		if (pill.price > 10.0)
		{
			sum += pill.price * pill.quantity;
		}
	}
	return sum;
}

int main()
{
	vector<Pharmacy> pills;
	int choice;
	do {
		cout << "\nPharmacy menu\n";
		cout << "1. Add medicine\n";
		cout << "2. Show all medicines\n";
		cout << "3. Total value (price > 10)\n";
		cout << "4. Price > 15\n";
		cout << "5. Expiry date\n";
		cout << "6. Exit.\n";
		cin >> choice;

		if (choice == 1)
		{
			Pharmacy p;
			p.get_data();
			pills.push_back(p);
		}
		else if (choice == 2)
		{
			display_all_medicines(pills);
		}
		else if (choice == 3)
		{
			double sum = total_price_pills_above_10(pills);
			cout << "Total value: " << sum << endl;
		}
		else if (choice == 4)
		{
			vector<Pharmacy> result = price_up_15(pills);
			display_all_medicines(result);
		}
		else if (choice == 5)
		{
			string date;
			cin.ignore();
			cout << "Enter date (YYYY-MM-DD): ";
			getline(cin, date);
			check_expiry_date(pills, date);
		}
	} while (choice != 6);
	return 0;
}
