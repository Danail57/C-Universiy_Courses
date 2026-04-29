#include "StudentCard.h"
#include <iostream>

using namespace std;

void StudentCard::get_data()
{
	Document::get_data();
	cout << "University: "; getline(cin, university);
}

void StudentCard::display()
{
	Document::display();
	cout << "University: " << university << endl;
}