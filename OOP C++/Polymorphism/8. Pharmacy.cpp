/*8. В една аптека всяко лекарство 
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
- извежда данните за най-скъпото лекарство, 
 от посочен производител;
- извежда данните за всички лекарства с цена 
над 12 лева, произведени от посочен производител;
- създава масив с данните на всички производители.*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
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
		cin.ignore();
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
	void print_manufacturers_only() override
	{
		cout << "Manufacturer: " << name << " | Address: " << address << " | Phone: " << phone << endl;

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

void create_manufacturers_array(vector<Medicine*> pharmacy)
{
	for (Medicine* m : pharmacy)
	{
		m->print_manufacturers_only();
	}
}

void show_medicines_up_12lv_price_from_manufacturer(vector<Medicine*> pharmacy)
{
	string target;
	cout << "Write the manufacturer name: ";
	getline(cin, target);

	bool found = false;
	for (Medicine* m : pharmacy)
	{
		if (m->is_produced_by(target) && m->get_price() > 12.0)
		{
			m->display();
			found = true;
		}
	}
	if (!found)
	{
		cout << "No medicines found from this criteria.";
	}
}

void the_most_expensive_pill_from_manufacturer(vector<Medicine*>& pharmacy)
{
	string target;
	cout << "Write the manufacturer name to search: ";
	getline(cin, target);

	int expensive_idx = -1;
	for (int i = 0; i < pharmacy.size(); i++)
	{
		if (pharmacy[i]->is_produced_by(target))
		{
			if (expensive_idx == -1 || pharmacy[i]->get_price() > pharmacy[expensive_idx]->get_price())
			{
				expensive_idx = i;
			}
		}
	}
	if (expensive_idx != -1)
	{
		pharmacy[expensive_idx]->display();
	}
	else
	{
		cout << "No medicines found from manufacturer: " << target << endl;
	}
}

int main()
{
	vector<Medicine*> pharmacy;
	int choice;

	do {
		cout << "\nPHARMACY MENU (Task 8)\n";
		cout << "1. Add new medicine\n";
		cout << "2. Display all data\n";
		cout << "3. Find the most expensive medicine from manufacturer\n";
		cout << "4. Create array by manufacturer\n";
		cout << "5. Medicines > 12lv price\n";
		cout << "0. Exit\n";
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;

		if (choice == 1)
		{
			int choice_number;
			cout << "(1 - Imported, 2 - Manufactured): "; cin >> choice_number;
			if (choice_number == 1)
			{
				Medicine* m = new ImportedMedicine();
				m->get_data();
				pharmacy.push_back(m);
			}

			else if (choice_number == 2)
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
			the_most_expensive_pill_from_manufacturer(pharmacy);
		}

		else if (choice == 4)
		{
			create_manufacturers_array(pharmacy);
		}

		else if (choice == 5)
		{
			show_medicines_up_12lv_price_from_manufacturer(pharmacy);
		}

	} while (choice != 0);

	for (Medicine* m : pharmacy)
	{
		delete m;
	}
}
