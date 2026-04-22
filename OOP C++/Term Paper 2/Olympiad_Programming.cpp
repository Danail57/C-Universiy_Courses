// Курсова работа

/*9. До участие в национална олимпиада по програмиране се допускат студенти
(име, ЕГН, университет, факултет, специалност, събрани точки) и 
ученици (име, ЕГН, училище, клас, събрани точки). Данните за всички участници
се съхраняват в масив, направете меню, което да изпълнява следните операции
- добавя данните на пореден участник
- извежда всички данни
- извежда данните на студентките от даден университет с повече от 50 точки
- създава масив с данните на всички ученици от зададено населено място*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UniversityStudents {
public:
	string name;
	string egn;
	string university;
	string faculty;
	string major;
	double points;

	void get_data();
	void display() const;
};

void UniversityStudents::get_data()
{
	cin.ignore();
	cout << "Name: "; getline(cin, name);
	cout << "EGN: "; cin >> egn;
	cin.ignore();
	cout << "University: "; getline(cin, university);
	cout << "Faculty: "; getline(cin, faculty);
	cout << "Major: "; getline(cin, major);
	cout << "Collected points: "; cin >> points;
}

void UniversityStudents::display() const
{
	cout << "Name: " << name << endl;
	cout << "EGN: " << egn << endl;
	cout << "University: " << university << endl;
	cout << "Faculty: " << faculty << endl;
	cout << "Major: " << major << endl;
	cout << "Points: " << points << endl;
}


class Students {
public:
	string name;
	string egn;
	string school;
	string school_class;
	double points;
	string town;

	void get_data();
	void display() const;
};

void Students::get_data()
{
	cin.ignore();
	cout << "Name: "; getline(cin, name);
	cout << "EGN: "; cin >> egn;
	cin.ignore();
	cout << "School: "; getline(cin, school);
	cout << "School class: "; getline(cin, school_class);
	cout << "Points: "; cin >> points;
	cin.ignore();
	cout << "Town: "; getline(cin, town);
}

void Students::display() const
{
	cout << "Name: " << name << endl;
	cout << "EGN: " << egn << endl;
	cout << "School: " << school << "| School class: " << school_class << endl;
	cout << "Points: " << points << endl;
}


// Functions - functionality
void display_all_data_for_university_students(vector<UniversityStudents> university_students)
{
	for (auto uni_student : university_students)
	{
		uni_student.display();
	}
}

void display_all_data_for_all_school_students(vector <Students> school_students)
{
	for (auto student : school_students)
	{
		student.display();
	}
}

bool is_female(string egn)
{
	if (egn.length() < 10) return false;
	int gender_digit = egn[8] - '0';
	return (gender_digit % 2 == 0);
}

void show_women_university_students_above_50_points(vector <UniversityStudents> women_university_students)
{
	for (auto university_student_woman : women_university_students)
	{
		if (university_student_woman.points > 50.0 && is_female(university_student_woman.egn))
		{
			university_student_woman.display();
		}
	}
}


void show_women_university_from_an_university(vector <UniversityStudents> women_university_students, string university)
{
	string university;
	cin.ignore();
	cout << "Write an university: "; getline(cin, university);
	for (auto uni : women_university_students)
	{
		if (uni.university == university && uni.points > 50.0 && is_female(uni.egn))
		{
			uni.display();
		}
	}
}

int main()
{
	vector <UniversityStudents> university_students;
	vector <Students> students;
	int choice;
	do {
		cout << "\nMenu\n";
		cout << "1. Add university student\n";
		cout << "2. Add school student\n";
		cout << "3. Display university student data\n";
		cout << "4. Display school student data\n";
		cout << "5. University students with points > 50\n";
		cout << "6. School students from a city\n";
		cout << "0. Exit\n";

		cin >> choice;
		if (choice == 1)
		{
			UniversityStudents university_student;
			university_student.get_data();
			university_students.push_back(university_student);
		}
		else if (choice == 2)
		{
			Students school_student;
			school_student.get_data();
			students.push_back(school_student);
		}
		else if (choice == 3)
		{
			display_all_data_for_university_students(university_students);
		}
		else if (choice == 4)
		{
			display_all_data_for_all_school_students(students);
		}
		else if (choice == 5)
		{			
			show_women_university_students_above_50_points(university_students);
			show_women_university_from_an_university(university_students);
		}
		else if (choice == 6)
		{

		}
	} while (choice != 0);
}

// za dovurshvane
