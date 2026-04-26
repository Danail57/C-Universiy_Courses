/*20. Да се състави програма, която съхранява в
масив следните данни за книгите в една библиотека:
- инвентарен номер - низ до 6 знака;
- автор - низ от 20 знака;
- заглавие - низ до 30 знака;
- обем на книгата (брой страници) - цяло число;
- цена - реално число;
- година на издаване
и извършва следните операции:
- създава масива с данните за книгите;
- извежда на екрана данните за всички книги;
- намира и извежда сумата от цените на всички
книги над 100 стр., издадени след 2000г;
- създава нов масив с данните на всички книги
от зададен автор с обем над 200 стр.*/

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;



class Library {
public:
	string author;
	string title;
	int pages;
	double price;
	int year;
	int quantity;

	void get_data();
	void display() const;
};

void Library::get_data()
{
	cin.ignore();
	cout << "Author: "; getline(cin, author);
	cin.ignore();
	cout << "Book title: "; getline(cin, title);
	cout << "Pages: "; cin >> pages;
	cout << "Price: " << " $"; cin >> price;
	cout << "Publication year: "; cin >> year;
}

void Library::display() const
{
	cout << "Author: " << author << endl;
	cout << "Book title: " << title << endl;
	cout << "Pages: " << pages << endl;
	cout << "Price: " << price << endl;
	cout << "Year of publication: " << year << endl;
}

void display_all_data(vector <Library> books)
{
	for (auto book : books)
	{
		book.display();
	}
}

vector < Library>books_above_200_pages(vector <Library> books, string author)
{
	vector <Library> result;
	for (auto book : books)
	{
		if (book.pages > 200 && book.author == author)
		{
			result.push_back(book);
		}
	}
	return result;
}

double show_price_books_above_100_pages_after_2000_year(vector <Library> books)
{
	double sum = 0;
	for (auto book : books)
	{
		if (book.pages > 100 && book.year > 2000)
		{
			sum += book.price;
		}
	}
	return sum;
}


int main()
{
	vector <Library> books;
	int choice;
	do {
		cout << "\nMenu\n";
		cout << "1. Add book\n";
		cout << "2. Display all data\n";
		cout << "3. Books above 200 pages\n";
		cout << "4. Price for book above 100 pages and published after 2000 year\n";
		cout << "5. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			Library lib;
			lib.get_data();
			books.push_back(lib);
		}
		else if (choice == 2)
		{
			display_all_data(books);
		}
		else if (choice == 3)
		{
			vector<Library> result = books_above_200_pages(books);
			display_all_data(result);
		}
		else if (choice == 4)
		{
			double sum = show_price_books_above_100_pages_after_2000_year(books);
			cout << "Total price: " << sum << endl;
		}
	} while (choice != 5);
}
