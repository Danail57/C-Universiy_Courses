/*Задача:

Въвеждате n книги.
Намирате книгата с най-висока цена.
Извеждате книгите с повече от 300 страници.
Изчислявате средната цена на книгите.*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Book {
	string title;
	string author;
	float price;
	int pages;
};


int main()
{
	Book books[1000];
	int n;
	cout << "Enter the number of books: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		cout << "Write the title: ";
		getline(cin, books[i].title);

		cout << "Write the author's name: ";
		getline(cin, books[i].author);

		cout << "Enter the price: ";
		cin >> books[i].price;

		cout << "Enter the pages: ";
		cin >> books[i].pages;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int max_price_index = 0;
	for (int i = 1; i < n; i++)
		if (books[i].price > books[max_price_index].price)
			max_price_index = i;

	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += books[i].price;

	float average_price = sum / n;
	cout << "\nBook with highest price:\n";
	cout << books[max_price_index].title << " - " << books[max_price_index].price << endl;

	cout << "\nBooks with more than 300 pages:\n";
	for (int i = 0; i < n; i++)
	{
		if (books[i].pages > 300)
			cout << books[i].title << endl;
	}
	cout << "\nAverage price of books: " << average_price << endl;
	return 0;
}
