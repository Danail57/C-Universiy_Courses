/*6. В една аптека всяко лекарство 
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
- извежда данните за най-евтиното лекарство,
внесено от посочен вносител;
- създава масив с данните за лекарствата,
произведени от посочен производител;
- създава масив с данните на всички производители*/

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
	virtual void get_data()
	{
		cout << "Medicine name: "; getline(cin, name);
		cout << "Price: "; cin >> price;
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
	virtual void print_manufacturers_only(){}
	double get_price() { return price; }

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
};

class ManufacturedMedicine : public Medicine {
private:
	string name, address, phone;
public:
	void get_data() override
	{
		//cin.ignore();
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
	void print_manufacturers_only() override
	{
		cout << "Manufacturer: " << name << " | Address: " << address << " | Phone: " << phone << endl;
	}
};


void display_all_data(vector<Medicine*> remedies)
{
	for (Medicine* m : remedies)
	{
		m->display();
	}
}

void create_array_by_manufacturer(vector<Medicine*> pharmacy)
{
	string target;
	
	cout << "Enter manufacturer name: "; 
	getline(cin, target);
	vector<Medicine*> filtered;

	for (Medicine* m : pharmacy)
	{
		if (m->is_produced_by(target))
		{
			filtered.push_back(m);
		}
	}
	if (filtered.empty())
	{
		cout << "No medicines found.\n";
	}
	else
	{
		for (Medicine* m : filtered)
		{
			m->display();
		}
	}
}

void create_manufacturers_array(vector<Medicine*> pharmacy)
{
	for (Medicine * m : pharmacy)
	{
		m->print_manufacturers_only();
	}
}

void cheapest_pill_from_importer(vector<Medicine*>& pharmacy)
{
	string target;
	cout << "Enter importer name to search: ";
	getline(cin, target);

	int cheapest_idx = -1;
	for (int i = 0; i < pharmacy.size(); i++)
	{
		if (pharmacy[i]->is_imported_by(target))
		{
			if (cheapest_idx == -1 || pharmacy[i]->get_price() < pharmacy[cheapest_idx]->get_price())
			{
				cheapest_idx = i;
			}
		}
	}
	if (cheapest_idx != -1)
	{
		pharmacy[cheapest_idx]->display();
	}
	else
	{
		cout << "No medicines found from importer: " << target << endl;
	}
}

int main()
{
	vector<Medicine*> pharmacy;
	int choice;

	do {
		cout << "\nPHARMACY MENU\n";
		cout << "1. Add new medicine\n";
		cout << "2. Display all data\n";
		cout << "3. Find cheapest medicine by importer\n";
		cout << "4. Create array by manufacturer\n";
		cout << "5. Create array of all manufacturers\n";
		cout << "6. Exit\n";
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			int type;
			cout << "Type (1 - Imported, 2 - Manufactured): "; cin >> type;
			cin.ignore();

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
			for (Medicine* m : pharmacy)
			{
				m->display();
			}
		}

		else if (choice == 3)
		{
			cheapest_pill_from_importer(pharmacy);
		}
		else if (choice == 4)
		{
			create_array_by_manufacturer(pharmacy);
		}
		else if (choice == 5)
		{
			create_manufacturers_array(pharmacy);
		}
	} while (choice != 6);

	for (Medicine* m : pharmacy)
	{
		delete m;
	}
}
