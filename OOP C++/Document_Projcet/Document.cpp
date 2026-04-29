#include "Document.h"
#include <iostream>

using namespace std;
void Document::display()
{
	cout << "Owner name: "; cin >> name;
	cout << "Document number: "; cin >> document_number;
	cout << "Issue date:\n"; issue_date.get_data();
}

void Document::display()
{
	cout << "Owner name: " << name << endl;
	cout << "Document number: " << document_number << endl;
	cout << "Issue date: ";
	issue_date.display();
}