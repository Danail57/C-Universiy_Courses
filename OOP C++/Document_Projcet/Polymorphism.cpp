#include <iostream>
#include <vector>
#include "StudentCard.h"
#include "LibraryCard.h"

using namespace std;
int main()
{
	vector <Document*> docs;
	int choice;

	do {
		cout << "\nDocument Menu\n";
		cout << "1. Add student card\n";
		cout << "2. Add library card\n";
		cout << "3. Display all data\n";
		cout << "4. Search by number\n";
		cout << "5. Extend validity\n";
		cout << "6. Expired cards\n";
		cout << "7. Valid cards\n";
		cout << "8. Cards expiring in N days\n";
		cout << "9. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			Document* d = new StudentCard;
			d->get_data();
			docs.push_back(d);
		}
		else if (choice == 2)
		{
			Document* d = new LibraryCard();
			d->get_data();
			docs.push_back(d);
		}
		else if (choice == 3)
		{
			for (auto d : docs)
			{
				d->display();
				cout << endl;
			}
		}
		else if (choice == 4)
		{
			int num;
			cout << "Write a document number: "; cin >> num;
			for (auto d : docs)
			{
				if (d->document_number == num)
				{
					d->display();
				}
			}
		}
		else if (choice == 5)
		{
			int num, days;
			cout << "Write a number: "; cin >> num;
			cout << "Days: "; cin >> days;
			for (auto d : docs)
			{
				if (d->document_number == num)
				{
					d->issue_date = d->issue_date + days;
				}
			}
		}
		else if (choice == 6)
		{
			Date today = current_date();
			for (auto d : docs)
			{
				if (d->issue_date < today)
				{
					d->display();
					cout << endl;
				}
			}
		}
		else if (choice == 7)
		{
			Date today = current_date();
			for (auto d : docs)
			{
				if (d->issue_date >= today)
				{
					d->display();
					cout << endl;
				}
			}
		}
		else if (choice == 8)
		{
			int days;
			cout << "Enter days: ";
			cin >> days;

			Date today = current_date();
			Date limit = today + days;

			for (auto d : docs)
			{
				if (d->issue_date >= today && d->issue_date <= limit)
				{
					d->display();
					cout << endl;
				}
			}
		}
	} while (choice != 9);
}