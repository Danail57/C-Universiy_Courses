#include "LibraryCard.h"
#include <iostream>

using namespace std;

void LibraryCard::get_data()
{
	Document::get_data();
	cout << "Books taken: ";
	cin >> books_taken;
}