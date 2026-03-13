//Да се състави програма, която съхранява в масив
//следната информация за лекарствата в една аптека:
// 
//-наименование - низ до 20 знака; 
//цена - реално число; 
//налично количество - цяло число; 
//дата, до която е годно за употреба 
// 
// и извършва следните операции, избирани от меню:
// 
//-добавя към масива данните на ново лекарство; 
//-извежда всички въведени данни; 
//-извежда имената лекарствата с налично количество 
//под зададен минимум; 
//-създава нов масив с данните на лекарствата с
//налични количества под 10 броя или цена под 12 лв; 
//-изключва от масива данните за всички лекарства с 
//изтекъл срок за годност към посочената дата.

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Pharmacy {
public:
	string name;
	double price;
	int quantity;
	string expiry_date;
	void get_data();
	void display() const;
};


void Pharmacy::get_data()
{
	cout << "Name of pill: "; cin >> name;
	cout << "Price per one: "; cin >> price;
	cout << "Quantity: "; cin >> quantity;
	cout << "Expiry date: "; cin >> expiry_date;
}

void Pharmacy::display() const
{
	cout << "Pill name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "In stock: " << quantity << endl;
	cout << "Expiry date: " << expiry_date << endl;
}

void show_bellow_minimum(const vector<Pharmacy>& stock, int min_quality)
{
	cout << "\nMedicines below " << min_quality << " units:\n";
	for (const auto& m : stock)
	{
		if (m.quantity < min_quality)
		{
			cout << "- " << m.name << " (" << m.quantity << " left)" << endl;
		}
	}
}


vector<Pharmacy> create_filtered_list(const vector<Pharmacy>& pharmacy_stock)
{
	vector <Pharmacy> filtered;
	for (const auto& p : pharmacy_stock)
	{
		if (p.quantity < 10 || p.price < 12.0)
		{
			filtered.push_back(p);
		}
	}
	return filtered;
}


void delete_expired(vector<Pharmacy>& pharmacy_stock, string current_date)
{
	for (int i = pharmacy_stock.size() - 1; i >= 0; i--)
	{
		if (pharmacy_stock[i].expiry_date < current_date)
		{
			cout << "Removingg expired: " << pharmacy_stock[i].name << endl;
			pharmacy_stock.erase(pharmacy_stock.begin() + i);
		}
	}
}

int main()
{
	vector<Pharmacy> stock;
	int choice;
	do 
	{
		cout << "\nPharmacy Menu\n";
		cout << "1. Add new medicine\n";
		cout << "2. Dispaly all data\n";
		cout << "3. Show medicines below minimum quantity\n";
		cout << "4. Create a special list (Qty < 10 or price < 12)\n";
		cout << "5. Remove expired medicines\n";
		cout << "6.Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			Pharmacy p;
			p.get_data();
			stock.push_back(p);
		}
		else if (choice == 2)
		{
			for (const auto& p : stock) p.display();
		}
		else if (choice == 3)
		{
			int min_quality;
			cout << "Write the minimum quality: "; cin >> min_quality;
			show_bellow_minimum(stock, min_quality);
		}
		else if (choice == 4)
		{
			vector<Pharmacy> special = create_filtered_list(stock);
			cout << "\nSpecial list created with " << special.size() << " items:\n";
			for (const auto& s : special) s.display();
		}
		else if (choice == 5)
		{
			string today;
			cout << "Enter current date (YYYY-MM-DD): "; cin >> today;
			delete_expired(stock, today);
		}
	} while (choice != 6);
	return 0;
}
