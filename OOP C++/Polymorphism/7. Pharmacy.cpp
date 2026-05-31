/*7. В една аптека всяко лекарство 
(наименование, цена, срок на годност) е доставено 
от доставчик (име, адрес, телефон) 
от производител (име, адрес, телефон) 
или от вносител (име, адрес, телефон). 
Данните за всяко лекарство, неговия доставчик 
и производител/вносител се съхраняват в масив.
Да се състави програма, която изпълнява от 
меню следните операции:
- добавя към масива данните на ново лекарство;
- извежда всички въведени данни;
- извежда данните за лекарствата с цена
под 10 лева, доставени от посочен производител;
- създава масив с данните за лекарствата,
внесени от посочен вносител;
- създава масив с данните на всички вносители.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Medicine {
protected:
	string name;
	double price;
	string expiry_date;
	string supplier_name, supplier_address, supplier_phone;

public:
	virtual ~Medicine(){}
	//ще се освободи цялата памет,
	// включително и специфичните променливи 
	// в наследниците

	virtual void get_data()
	{
		cin.ignore();
		cout << "Medicine name: "; getline(cin, name);
		cout << "Medicine price: "; cin >> price;
		cin.ignore();
		cout << "Expiry date (YYYY-MM-DD): "; getline(cin, expiry_date);
		cout << "Supplier name: "; getline(cin, supplier_name);
		cout << "Supplier address: "; getline(cin, supplier_address);
		cout << "Supplier phone: "; getline(cin, supplier_phone);
	}

	virtual void display()
	{
		cout << "\nMedicine: " << name << " | Price: " << price << " | Expiry: " << expiry_date << endl;
		cout << "Supplier: " << supplier_name << " (Addr: " << supplier_address << ", Phone: " << supplier_phone << ")" << endl;
	}

	virtual bool is_imported_by(string target_name)
	{
		return false;
	}
	virtual bool is_produced_by(string target_name)
	{
		return false;
	}
	virtual void print_importers_only(){}
	double get_price()
	{
		return price;
	}
};

class ImportedMedicine : public Medicine {
private:
	string name, address, phone;

public:
	void get_data() override
	{
		Medicine::get_data();
		cout << "Importer name: "; getline(cin, name);
		cout << "Address importer name: "; getline(cin, address);
		cout << "Importer phone: "; getline(cin, phone);
	}

	void display() override
	{
		Medicine::display();
		cout << "Importer name: " << name << endl;
		cout << "Address importer name:  " << address << endl;
		cout << "Importer phone: " << phone << endl;
	}

	bool is_imported_by(string target_name) override
	{
		return name == target_name;
	}
	void print_importers_only() override
	{
		cout << "Importer: " << name << " | Address: " << address << " | Phone: " << phone << endl;
	}

};

class ManufacturedMedicine : public Medicine {
private:
	string name, address, phone;
public:
	void get_data() override
	{
		Medicine::get_data();
		cout << "Manufacturer name: "; getline(cin, name);
		cout << "Address manufacturer name: "; getline(cin, address);
		cout << "Manufacturer phone: "; getline(cin, phone);
	}

	void display() override
	{
		Medicine::display();
		cout << "Manufacturer name: " << name << endl;
		cout << "Address manufacturer name:  " << address << endl;
		cout << "Manufacturer phone: " << phone << endl;
	}

	bool is_produced_by(string target_name) override
	{
		return name == target_name;
	}
};

void display_all_data(vector<Medicine*> remedies)
{
	for (Medicine* m : remedies)
	{
		m->display();
	}
}

void create_importers_array(vector<Medicine*> pharmacy)
{
	for (Medicine* m : pharmacy)
	{
		m->print_importers_only();
	}
}

void show_medicines_below_10lv_price_from_manufacturer(vector<Medicine*> pharmacy)
{
	string target;
	cout << "Enter manufacturer name: ";
	getline(cin, target);

	bool found = false;
	cout << "\nMedicines under 10 lv. from " << target << " \n";

	for (Medicine* m : pharmacy)
	{
		if (m->is_produced_by(target) && m->get_price() < 10.0)
		{
			m->display();
			found = true;
		}
	}
	if (!found)
	{
		cout << "No medicines found from this criteria.\n";
	}
}

void create_array_by_importer(vector<Medicine*> pharmacy)
{
	string target;
	cout << "Write the importer name: ";
	getline(cin, target);
	vector<Medicine*> filtered;

	for (Medicine* m : pharmacy)
	{
		if (m->is_imported_by(target))
		{
			filtered.push_back(m);
		}
	}
	if (filtered.empty())
	{
		cout << "No medicines found from importer: " << target << "\n";
	}
	else
	{
		for (Medicine* m : filtered)
		{
			m->display();
		}
	}
}

int main()
{
	vector<Medicine*> pharmacy;
	int choice;

	do {
		cout << "\nPHARMACY MENU (Task 7)\n";
		cout << "1. Add new medicine\n";
		cout << "2. Display all data\n";
		cout << "3. Medicines below 10 lv price by manufacturer\n";
		cout << "4. Create array by importer\n";
		cout << "5. Create array of all importers\n";
		cout << "6. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			int type;
			cout << "Type (1- Imported, 2 - Manufactured): "; cin >> type;
			if (type == 1)
			{
				Medicine* m = new ImportedMedicine();
				m->get_data();
				pharmacy.push_back(m);
			}
			else if (type == 2)
			{
				Medicine* m = new ManufacturedMedicine();
				m->get_data();
				pharmacy.push_back(m);
			}
		}

		else if (choice == 2)
		{
			display_all_data(pharmacy);
		}
		else if (choice == 3)
		{
			show_medicines_below_10lv_price_from_manufacturer(pharmacy);
		}
		else if (choice == 4)
		{
			create_array_by_importer(pharmacy);
		}
		else if (choice == 5)
		{
			create_importers_array(pharmacy);
		}
	} while (choice != 6);
	for (Medicine* m : pharmacy)
	{
		delete m;
	}
}
