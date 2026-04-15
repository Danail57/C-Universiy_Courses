#include <iostream>
#include <vector>
#include <string>
using namespace std;


class StudentCard{
public:
	string name;
	int faculty_number;
	string university_major;
	void get_data();
	void display() const;
};

void StudentCard::get_data()
{
	cin.ignore();
	cout << "Name: "; getline(cin, name);
	cout << "Faculty number: "; cin >> faculty_number;
	cin.ignore();
	cout << "University major: "; getline(cin, university_major);
}

void StudentCard::display() const
{
	cout << "Student name: " << name << endl;
	cout << "Faculty number: " << faculty_number << endl;
	cout << "University major: " << university_major << endl;
}

void display_all_cards(const vector <StudentCard> student_cards)
{
	for (auto student_card : student_cards)
	{
		student_card.display();
	}
}

void delete_by_faculty_number(vector <StudentCard>& cards, int faculty_number)
{
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i].faculty_number == faculty_number)
		{
			cards.erase(cards.begin() + i);
			i--;
		}
	}
}


void delete_by_index(vector <StudentCard>& cards, int index)
{
	if (index >= 0 && index < cards.size())
	{
		cards.erase(cards.begin() + index);
	}
}

void show_card_by_index(vector <StudentCard> cards, int index)
{
	if (index >= 0 && index < cards.size())
	{
		cout << "Name: " << cards[index].name << endl;
		cout << "Faculty number: " << cards[index].faculty_number << endl;
		cout << "Speciality: " << cards[index].university_major << endl;
	}
	else
	{
		cout << "Invalid index" << endl;
	}
}

int main()
{
	vector <StudentCard> cards;
	int choice;
	do {
		cout << "\nMenu:\n";
		cout << "1. Add student card\n";
		cout << "2. Display all data\n";
		cout << "3. Delete a student card by index\n";
		cout << "4. Delete a student card by faculty number\n";
		cout << "5. Show the next student card by its index\n";
		cout << "6. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			StudentCard c;
			c.get_data();
			cards.push_back(c);
		}
		else if (choice == 2)
		{
			display_all_cards(cards);
		}
		else if (choice == 3)
		{
			int index;
			cout << "Enter index: ";
			cin >> index;
			delete_by_index(cards, index - 1);
		}
		else if (choice == 4)
		{
			int faculty_number;
			cout << "Enter faculty number: ";
			cin >> faculty_number;
			delete_by_faculty_number(cards, faculty_number);
		}
		else if (choice == 5)
		{
			int index;
			cout << "Write index: "; cin >> index;
			show_card_by_index(cards, index - 1);
		}
	} while (choice != 6);
}
