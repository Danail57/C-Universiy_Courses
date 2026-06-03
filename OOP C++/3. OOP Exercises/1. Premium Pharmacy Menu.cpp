/*1. Да се състави програма, която съхранява
в масив следната информация за лекарствата в една
аптека :
-наименование - низ до 20 знака;
-цена - реално число;
-налично количество - цяло число;
-дата, до която е годно за употреба
и извършва следните операции, избирани от меню :

-добавя към масива данните на ново лекарство;
-извежда всички въведени данни;
-извежда имената на лекарствата с цена над 5 лв;
-създава нов масив с данните на лекарствата 
с налични количества под 10 броя;
-cъздава нов масив с данните на лекарствата
с цена над 15 лв;
-извежда загубата от лекарствата с изтекъл срок
към зададена дата
-създава нов масив с данните на лекарствата 
с изтичаща годност днес
-създава нов масив с имената количествата
на лекарствата с изтичащ срок на годност на
зададена дата.
-изключва от масива данните за всички лекарства с изтекъл срок за годност към посочената 
дата
-създава нов масив с данните на лекарствата 
с налични количества под 10 броя
или цена под 12 лв;
-извежда имената лекарствата с налично 
количество под зададен минимум*/

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
	void display();
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

void Pharmacy::display()
{
	cout << "Medicine name: " << medicine_name << endl;
	cout << "Price: " << price << endl;
	cout << "In stock: " << quantity << endl;
	cout << "Expiry date: " << expiry_date << endl;
}

void display_all_data(vector<Pharmacy> pills)
{
	for (auto pill : pills)
	{
		pill.display();
	}
}

//
vector<Pharmacy> get_low_stock_or_cheap(vector<Pharmacy> pills)
{
	vector <Pharmacy> result;
	for (auto pill : pills)
	{
		if (pill.quantity < 10 || pill.price < 12.0)
		{
			result.push_back(pill);
		}
	}
	return result;
}

void show_medicines_below_minimum(vector<Pharmacy> pills, int minimum)
{
	bool found = false;
	for (auto pill : pills)
	{
		if (pill.quantity < minimum)
		{
			cout << pill.medicine_name << " (In stock: " << pill.quantity << ")\n";
			found = true;
		}
	}
	if (!found)
	{
		cout << "All medicines are above the requested minimum.\n";
	}
}

// 9. Изключва от масива данните за всички 
// лекарства с изтекъл срок
void remove_expired_medicines(vector<Pharmacy>& pills, const string& current_date)
{
	int initial_size = pills.size();
	for (int i = pills.size() - 1; i >= 0; i--)
	{
		if (pills[i].expiry_date < current_date)
		{
			pills.erase(pills.begin() + i);
		}
	}
	cout << "Removed " << (initial_size - pills.size()) << " expired medicines.\n";
}

// 8. Създава нов масив само с имената и 
// количествата (в случая връщаме обекти,
// но показваме само тях)

vector<Pharmacy> get_expiring_on_date(vector<Pharmacy> pills, string target_date)
{
	vector <Pharmacy> result;
	for (auto pill : pills)
	{
		if (pill.expiry_date == target_date)
		{
			result.push_back(pill);
		}
	}
	return result;
}

vector<Pharmacy> get_expiring_today(vector<Pharmacy> pills, string today)
{
	vector<Pharmacy> result;
	for (auto pill : pills)
	{
		if (pill.expiry_date == today)
		{
			result.push_back(pill);
		}
	}
	return result;
}

// Извежда загубата от лекарствата с изтекъл 
// срок към зададена дата

void show_loss_from_expired(vector<Pharmacy> pills, string current_date)
{
	double total_loss = 0;
	for (auto pill : pills)
	{
		if (pill.expiry_date < current_date)
		{
			total_loss += (pill.price * pill.quantity);
		}
	}
	cout << "Total financial loss from expired medicine: " << total_loss << endl;
}

//Създава нов масив с налични количества под 10 броя
vector <Pharmacy> get_low_stock(vector<Pharmacy> pills)
{
	vector <Pharmacy> result;
	for (auto pill : pills)
	{
		if (pill.quantity < 10)
		{
			result.push_back(pill);
		}
	}
	return result;
}

vector<Pharmacy> medicines_price_above_15(vector<Pharmacy> pills)
{
	vector <Pharmacy> result;
	for (auto pill : pills)
	{
		if (pill.price > 15.0)
		{
			result.push_back(pill);
		}
	}
	return result;
}

void show_medicines_up_5lv_price(vector<Pharmacy> pills)
{
	bool found = false;
	for (auto pill : pills)
	{
		if (pill.price > 5.0)
		{
			cout << "- " << pill.medicine_name << " (" << pill.price << " lv.)\n";
			found = true;
		}
	}
	if (!found) cout << "No medicines with price above 5 lv.\n";
}

int main()
{
	vector <Pharmacy> stock;
	int choice;
	do {
		cout << "\nPREMIUM PHARMACY MENU\n";
		cout << "1. Add new medicine\n";
		cout << "2. Display all data\n";
		cout << "3. Get low stock or cheap\n";
		cout << "4. Show medicines below minimum\n";
		cout << "5. Remove expired medicines\n";
		cout << "6. Get expiring on date\n";
		cout << "7. Show financial loss from expired medicine\n";
		cout << "8. Get low stock\n";
		cout << "9. Medicines price above 15lv\n";
		cout << "10. Medicines price above 5lv\n";
		cout << "0. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			Pharmacy p;
			p.get_data();
			stock.push_back(p);
		}
		else if (choice == 2)
		{
			display_all_data(stock);
		}
		else if (choice == 3)
		{
			get_low_stock_or_cheap(stock);
		}
		else if (choice == 4)
		{
			int min_input;
			cout << "Write the minimal quantity: "; cin >> min_input;
			show_medicines_below_minimum(stock, min_input);
		}
		else if (choice == 5)
		{
			string date;
			cout << "Write a date: (YYYY-MM-DD): ";
			getline(cin, date);
			remove_expired_medicines(stock, date);
		}
		else if (choice == 6)
		{
			string date;
			cout << "Write a date:";
			getline(cin, date);
			vector<Pharmacy> date_expiry = get_expiring_on_date(stock, date);
			for (auto pill : date_expiry)
			{
				cout << "Medicine: " << pill.medicine_name << "| Quantity left: " << pill.quantity << endl;
			}
		}
		else if (choice == 7)
		{
			string date;
			cout << "Write a date: ";
			getline(cin, date);
			show_loss_from_expired(stock, date);
		}
		else if (choice == 8)
		{
			vector<Pharmacy> low_stock = get_low_stock(stock);
			display_all_data(low_stock);
		}
		else if (choice == 9)
		{
			vector<Pharmacy> expensive = medicines_price_above_15(stock);
			display_all_data(expensive);
		}
		else if (choice == 10)
		{
			show_medicines_up_5lv_price(stock);
		}

	} while (choice != 0);
}
