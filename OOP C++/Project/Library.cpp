#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;


class Date {
public:
	short int day;
	short int month;
	short int year;

	void get_data();
	void display() const;

	bool operator<(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator!=(const Date& other) const;
	Date operator+(int days) const;
};

Date current_date()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	Date d;
	d.day = now->tm_mday;
	d.month = now->tm_mon + 1;
	d.year = now->tm_year + 1900;

	return d;
}


void Date::get_data()
{
	cout << "Day: "; cin >> day;
	cout << "Month: "; cin >> month;
	cout << "Year: "; cin >> year;
}

void Date::display() const
{
	cout << year << "-";

	if (month < 10) cout << "0";
	cout << month << "-";

	if (day < 10) cout << "0";
	cout << day << endl;
}

bool Date::operator<(const Date& other) const
{
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

bool Date::operator>(const Date& other) const { return other < *this; }
bool Date::operator<=(const Date& other) const { return !(*this > other); }
bool Date::operator>=(const Date& other) const { return !(*this < other); }

bool Date::operator!=(const Date& other) const
{
	return day != other.day || month != other.month || year != other.year;
}

Date Date::operator+(int days) const
{
	Date result = *this;

	tm time = {};
	time.tm_mday = result.day + days;
	time.tm_mon = result.month - 1;
	time.tm_year = result.year - 1900;

	mktime(&time);

	result.day = time.tm_mday;
	result.month = time.tm_mon + 1;
	result.year = time.tm_year + 1900;

	return result;
}


class Document {
public:
	int document_number;
	string owner_name;
	Date issue_date;
	Date expiry_date;
	void get_data();
	void display() const;
};


void Document::get_data()
{
	cout << "Document number: "; cin >> document_number;
	cin.ignore();
	cout << "Owner: "; getline(cin, owner_name);
	cout << "Issue date: (YYYY-MM-DD):\n"; issue_date.get_data();
	cout << "Expiry date: (YYYY-MM-DD):\n"; expiry_date.get_data();
}

void Document::display() const
{
	cout << "Document number: " << document_number << endl;
	cout << "Owner: " << owner_name << endl;
	cout << "Issue date: (YYYY-MM-DD): "; issue_date.display();
	cout << "Expiry date: (YYYY-MM-DD): "; expiry_date.display();
}


class LibraryCard : public Document{
public:
	int reader_number;
	int books_borrowed;
	Date creation_date;

	void get_data();
	void display() const;
};

void LibraryCard::get_data()
{
	Document::get_data();

	cout << "Reader number: "; cin >> reader_number;
	cout << "Borrowed books: "; cin >> books_borrowed;
	cin.ignore();
	cout << "Creation date (YYYY-MM-DD): ";
	creation_date.get_data();
}


void LibraryCard::display() const
{
	Document::display();
	cout << "Reader number: " << reader_number << endl;
	cout << "Borrowed books: " << books_borrowed << endl;
}


class StudentCard : public Document{
public:
	int faculty_number;
	string university_major;
	Date creation_date;
	void get_data();
	void display() const;
};

void StudentCard::get_data()
{
	Document::get_data();
	cout << "Faculty number: "; cin >> faculty_number;
	cin.ignore();
	cout << "University major: "; getline(cin, university_major);
	cout << "Creation date:\n";
	creation_date.get_data();
}

void StudentCard::display() const
{
	Document::display();
	cout << "Faculty number: " << faculty_number << endl;
	cout << "University major: " << university_major << endl;
}


void expired_cards(vector <Document> docs)
{
	Date today = current_date();
	for (auto d : docs)
	{
		if (d.expiry_date < today)
			d.display();
	}
}


void display_all_reading_cards(const vector<LibraryCard>& library_cards)
{
	for (auto cart : library_cards)
		cart.display();
}

void valid_cards(const vector<Document>& docs)
{
	Date today = current_date();

	for (const auto& d : docs)
		if (d.expiry_date >= today)
			d.display();
}


void extend_document(vector<Document>& docs)
{
	int num, days;
	cout << "Document number: ";
	cin >> num;
	cout << "Days to extend: ";
	cin >> days;

	for (auto& d : docs)
	{
		if (d.document_number == num)
		{
			d.expiry_date = d.expiry_date + days;
			cout << "Extended!\n";
			return;
		}
	}
	cout << "Not found!\n";
}

void expiring_soon(const vector<Document>& docs)
{
	int days;
	cout << "Days: ";
	cin >> days;

	Date today = current_date();
	Date future = today + days;

	for (const auto& d : docs)
	{
		if (d.expiry_date >= today && d.expiry_date <= future)
			d.display();
	}
}

vector<StudentCard> display_student_cards_on_date(const vector<StudentCard>& student_cards, const Date& target_date)
{
	vector<StudentCard> result;
	for (auto student_cart : student_cards)
	{
		if (student_cart.creation_date.day == target_date.day &&
			student_cart.creation_date.month == target_date.month &&
			student_cart.creation_date.year == target_date.year)
		{
			result.push_back(student_cart);
		}
	}
	return result;
}


vector<LibraryCard> display_all_cards_given_on_a_date(const vector <LibraryCard>& cards, const Date& target_date)
{
	vector<LibraryCard> result;
	for (const auto& card : cards)
	{
		if (card.creation_date.day == target_date.day &&
			card.creation_date.month == target_date.month &&
			card.creation_date.year == target_date.year)
		{
			result.push_back(card);
		}
	}
	return result;
}


void search_number_of_document(const vector<Document>& documents)
{
	int number;
	cout << "Write the document number to search: ";
	cin >> number;

	for (auto d : documents)
	{
		if (d.document_number == number)
		{
			cout << "Document found:\n";
			d.display();
			return;
		}
	}
	cout << "Document not found.\n";
}


int main()
{
	vector<Document> documents;
	vector<LibraryCard> library_cards;
	vector<StudentCard> student_cards;
	int choice;

	do {
		cout << "\nLibrary menu\n";
		cout << "1. Add document\n";
		cout << "2. Add student card\n";
		cout << "3. Add library card\n";
		cout << "4. Search number of a document\n";
		cout << "5. Expired cards\n";
		cout << "6. Valid cards\n";
		cout << "7. Extend document\n";
		cout << "8. Expiring soon\n";
		cout << "9. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			Document d;
			d.get_data();
			documents.push_back(d);
		}
		else if (choice == 2)
		{
			StudentCard s;
			s.get_data();
			student_cards.push_back(s);
			documents.push_back(s);
		}
		else if (choice == 3)
		{
			LibraryCard l;
			l.get_data();
			library_cards.push_back(l);
			documents.push_back(l);
		}
		else if (choice == 4)
		{
			search_number_of_document(documents);
		}
		else if (choice == 5)
		{
			expired_cards(documents);
		}
		else if (choice == 6)
		{
			valid_cards(documents);
		}
		else if (choice == 7)
		{
			extend_document(documents);
		}
		else if (choice == 8)
		{
			expiring_soon(documents);
		}
	} while (choice != 9);
	return 0;
}
