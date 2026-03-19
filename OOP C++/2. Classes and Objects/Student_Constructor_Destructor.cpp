#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Student {
public:
	string name;
	string ID;
	int school_marks[5];
	int course;

	//default constructor
	Student()
	{
		name = "Unknown";
		ID = "0000000000";
		for (int i = 0; i < 5; i++)
		{
			school_marks[i] = 0;
		}
		course = 1;
		cout << "Student created: " << name << endl;
	}


	// with parameters
	Student(const string& n, const string& id, const int marks[5], int course_enrolled)
	{
		name = n;
		ID = id;
		for (int i = 0; i < 5; i++)
		{
			school_marks[i] = marks[i];
		}
		course = course_enrolled;
		cout << "Student created: " << name << endl;
	}

	// destructor
	~Student()
	{
		cout << "Student destroyed: " << name << endl;
	}

	double grade() const
	{
		double sum = 0;
		for (int i = 0; i < 5; i++)
			sum += school_marks[i];
		return sum / 5;
	}
	void display() const
	{
		cout << "\nStudent name: " << name << endl;
		cout << "ID: " << ID << endl;
		cout << "School marks: ";
		for (int i = 0; i < 5; i++)
			cout << school_marks[i] << " ";
		cout << "\nCourse: " << course << endl;
		cout << "Average marks: " << grade() << endl;
	}
};

string get_gender(const string& ID)
{
	int gender_digit = ID[8] - '0';
	return (gender_digit % 2 == 0) ? "female" : "male";
}

int main()
{
	vector<Student> students;
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
			string name, ID;
			int marks[5], course;

			cout << "Name of student: "; cin >> name;
			cout << "ID: "; cin >> ID;
			cout << "Enter 5 school marks: ";
			for (int i = 0; i < 5; i++) cin >> marks[i];
			cout << "Course: "; cin >> course;

			students.emplace_back(name, ID, marks, course);
		}
		else if (choice == 2)
		{
			for (const auto& s : students)
				s.display();
		}
		else if (choice == 3)
		{
			for (int i = 0; i < students.size(); i++)
				cout << "Student[" << i + 1 << "] gender: " << get_gender(students[i].ID) << endl;
		}

	} while (choice != 4);

	return 0;
}
