#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;


class Student {
public:
	//~Student();
	//Student(string name, string ID, int school_marks, int course);
	string name;
	string ID;
	int school_marks[5];
	int course;

	void get_data();
	void display() const;
	void school_mark();
	double grade() const;
};


void Student::school_mark()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a mark for the student: "; cin >> school_marks[i];
	}
}

void Student::get_data()
{
	cout << "Name of student: "; cin >> name;
	cout << "ID: "; cin >> ID;
	cout << "Write 5 school marks: "; school_mark();
	cout << "Course: "; cin >> course;
}

void Student::display() const
{
	cout << "Student name: " << name << endl;
	cout << "ID of the student: " << ID << endl;
	cout << "School marks displayed: ";
	for (int i = 0; i < 5; i++)
	{
		cout << school_marks[i] << " ";
	}
	cout << endl;

	cout << "Course of the student: " << course << endl;
	cout << "Average school marks: " << grade() << endl;
}


void get_birthday_of_the_student(vector<string> IDs)
{
	for (int i = 0; i < IDs.size(); i++)
	{
		string id = IDs[i];
		int year = (id[0] - '0') * 10 + (id[1] - '0');
		int month = (id[2] - '0') * 10 + (id[3] - '0');
		int day = (id[4] - '0') * 10 + (id[5] - '0');
		if (month > 40) 
		{
			month -= 40;
			year += 2000;
		}
		else if (month > 20)
		{
			month -= 20;
			year += 1800;
		}
		else
		{
			year += 1900;
		}
		cout << "ID [" << i + 1 << "] date of birth: " << day << "." << month << "." << year << endl;
	}
}

void get_age_of_a_student(const vector<int>& age_years)
{
	time_t t = time(0); // текущо време
	tm* now = localtime(&t); // преобразува времето в структура (година, месец, ден
	int current_year = now->tm_year + 1900; // връща години след 1900
	for (int i = 0; i < age_years.size(); i++)
	{
		int age = current_year - age_years[i];
		cout << "Student[" << i + 1 << "] age: " << age << endl;
	}
}


string get_gender(const string& ID)
{
	int gender_digit = ID[8] - '0';
	return (gender_digit % 2 == 0) ? "female" : "male";
}

double Student::grade() const
{
	double sum = 0;

	for (int i = 0; i < 5; i++)
	{
		sum += school_marks[i];
	}
	return sum / 5;
}


int main()
{
	vector <Student> students;
	int choice;
	do 
	{
		cout << "\nMENU\n";
		cout << "1. Add a student\n";
		cout << "2. Show all students\n";
		cout << "3. Show genders\n";
		cout << "4. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			Student s;
			s.get_data();
			students.push_back(s);
		}
		else if (choice == 2)
		{
			for (int i = 0; i < students.size(); i++)
			{
				students[i].display();
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < students.size(); i++)
			{
				cout << "Student[" << i + 1 << "] gender: " << get_gender(students[i].ID) << endl;
			}
		}

	} while (choice != 4);
	return 0;
}
