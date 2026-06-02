/*16. До участие в национална олимпиада по програмиране
се допускат студенти (име, ЕГН, университет, факултет, 
специалност, събрани точки) и
ученици (име, ЕГН, училище, клас, събрани точки). 
Данните за всички участници се съхраняват в един масив.

Да се състави програма, която изпълнява от меню следните операции:
- добавя към масива данните на пореден участник;
- извежда всички въведени данни;
- извежда данните на студентите от зададена 
специалност с повече от 25 точки;
- създава масив с данните на всички участници мъже.
- извежда данните на участника с най-много точки;
- създава масив с данните на всички участнички с 
повече от 30 точки
-извежда данните на студентките от зададен
университет с повече от 50 точки
- cъздава масив с данните на всички ученички
от зададен клас.
- извежда данните на студентите мъже над 20 г. 
от зададен университет
- извежда името на ученика с най-много точки
- извежда данните на участничките от 
зададено населено място;*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool is_female(string EGN)
{
	if (EGN.length() < 10) return false;
	int gender_digit = EGN[8] - '0';
	return (gender_digit % 2 != 0);
}

bool is_male(string EGN)
{
	if (EGN.length() < 10) return false;
	int gender_digit = EGN[8] - '0';
	return (gender_digit % 2 == 0);
}


int get_birth_year(string EGN)
{
	int year = stoi(EGN.substr(0, 2));
	int month = stoi(EGN.substr(2, 2));
	if (month > 40)
	{
		year += 2000;
	}

	else if (month > 20)
	{
		year += 1800;
	}

	else
	{
		year += 1900;
	}
	return year;
}


class Participant {
protected:
	string name;
	string EGN;
	double points;
	double grade;
	string city;

public:
	virtual ~Participant(){}

	virtual void get_data()
	{
		cin.ignore();
		cout << "Name: "; getline(cin, name);
		cout << "EGN: "; cin >> EGN;
		cin.ignore();
		cout << "Town: "; getline(cin, city);
		cout << "Grade: "; cin >> grade;
		cout << "Points: "; cin >> points;
	}

	virtual void display()
	{
		cout << "Name: " << name << endl;
		cout << "EGN: " << EGN << endl;
		cout << "Town: " << city << endl;
		cout << "Grade: " << grade << endl;
		cout << "Points: " << points << endl;
	}

	//извежда данните на студентите от зададена
	//специалност с повече от 25 точки
	virtual bool show_uni_students_from_major_with_more_25points(double points)
	{
		return false;
	}

	// извежда данните на участника
	// с най-много точки
	virtual void print_the_participant_with_the_most_points(){}

	//извежда данните на студентките от зададен
	//университет с повече от 50 точки
	virtual bool show_women_uni_students_above_50_points(string university)
	{
		return false;
	}

	//извежда данните на студентите мъже над 20 г.
	//от зададен университет
	virtual bool show_men_uni_students_higher_than_20_years_old_from_university(string university)
	{
		return false;
	}

	//извежда името на ученика с най-много точки
	virtual bool show_student_with_the_most_points(double points)
	{
		return false;
	}

	//извежда данните на участничките от
	//зададено населено място;
	virtual bool is_from_city(string city)
	{
		return false;
	}
	virtual string get_EGN() { return EGN; }
	virtual string get_name() { return name; }
	virtual double get_points() { return points; }
	virtual bool is_school_student() { return false; }
	virtual bool is_uni_student() { return false; }
	virtual string get_university() { return " "; }
	virtual string get_speciality() { return " "; }
};

class UniversityStudent : public Participant {
private:
	string university;
	string faculty;
	string speciality;

public:
	void get_data() override
	{
		Participant::get_data();
		cin.ignore();
		cout << "University: "; getline(cin, university);
		cout << "Faculty: "; getline(cin, faculty);
		cout << "Major: "; getline(cin, speciality);
	}

	void display() override
	{
		Participant::display();
		cout << "University: " << university << endl;
		cout << "Faculty: " << faculty << endl;
		cout << "Major: " << speciality << endl;
	}

	bool is_from_city(string target_city)
	{
		return city == target_city;
	}
	bool is_uni_student(){ return true; }
	string get_university(){ return university; }
};


class Student : public Participant {
private:
	string school;
	double grade;

public:
	void get_data() override
	{
		Participant::get_data();
		cin.ignore();
		cout << "School: "; getline(cin, school);
		cout << "Grade: "; cin >> grade;
	}

	void display() override
	{
		Participant::display();
		cout << "School: " << school << endl;
		cout << "Grade: " << grade << endl;
	}

	bool is_school_student() override
	{
		return true;
	}
};

void display_all_data(vector<Participant*> participants)
{
	for (Participant* p : participants)
	{
		p->display();
	}
}

void show_woman_participants_from_city(vector<Participant*> participants, string city)
{
	for (Participant* p : participants)
	{
		if (p->is_from_city(city) && is_female(p->get_EGN()))
		{
			p->display();
		}
	}
}

void show_the_participant_with_the_most_points(vector<Participant*> participants)
{
	Participant* max_participant = participants[0];
	for (size_t i = 1; i < participants.size(); i++)
	{
		if (participants[i]->get_points() > max_participant->get_points())
		{
			max_participant = participants[i];
		}
	}
	cout << "The participant with the most points\n";
	max_participant->display();
}

void show_student_with_the_most_points(vector<Participant*> participants)
{
	int max_index = -1;
	double max_points = -1;
	for (size_t i = 0; i < participants.size(); i++)
	{
		if (participants[i]->is_school_student())
		{
			if (participants[i]->get_points() > max_points)
			{
				max_points = participants[i]->get_points();
				max_index = i;
			}
		}
	}
	if (max_index != -1)
	{
		cout << "Student with the most points: " << participants[max_index]->get_name() << " with " << max_points << endl;
	}
	else
	{
		cout << "No students typed in" << endl;
	}
}

void show_men_uni_students_higher_than_20_years_old_from_university(vector<Participant*> participants, string university, int current_year)
{
	int found_any = -1;
	for (size_t i = 0; i < participants.size(); i++)
	{
		if (participants[i]->is_uni_student() && participants[i]->get_university() == university)
		{
			if (is_male(participants[i]->get_EGN()))
			{
				int birth_year = get_birth_year(participants[i]->get_EGN());
				int age = current_year - birth_year;
				if (age > 20)
				{
					found_any = 1;
					participants[i]->display();
					cout << "Age: " << age << endl;
				}
			}
		}
	}
	if (found_any == -1)
	{
		cout << "No male university students to be 20 years old or more" << endl;
	}
}

void show_women_university_students_above_50_points(vector<Participant*> woman_uni_student, string university)
{
	for (Participant* p : woman_uni_student)
	{
		if (p->show_women_uni_students_above_50_points(university))
		{
			p->display();
		}
	}
}

void show_uni_students_from_major_with_more_25points(vector<Participant*> participants, string speciality, double limit_points)
{
	int found_any = -1;
	for (size_t i = 0; i < participants.size(); i++)
	{
		if (participants[i]->is_uni_student())
		{
			if (participants[i]->get_speciality() == speciality && participants[i]->get_points() > limit_points)
			{
				found_any = 1;
				participants[i]->display();
			}
		}
	}
	if (found_any == -1)
	{
		cout << "No data matching the criteria" << endl;
	}
}

int main()
{
	vector<Participant*> participants;
	int choice;

	do {
		cout << "\nPREMIUM STUDENT INFO\n";
		cout << "1. Add new participant\n";
		cout << "2. Display all data\n";
		cout << "3. Show woman participants from city\n";
		cout << "4. Show the participant with the most points\n";
		cout << "5. Show student with the most points\n";
		cout << "6. Show men uni students older than 20 years old from university\n";
		cout << "7. Show woman university students above 50 points\n";
		cout << "8. Show uni students from major with more than 25points\n";
		cout << "0. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			int type;
			cout << "Type (1 - Student, 2 - University Student): "; cin >> type;
			if (type == 1)
			{
				Participant* p = new Student();
				p->get_data();
				participants.push_back(p);
			}
			else if (type == 2)
			{
				Participant* p = new UniversityStudent();
				p->get_data();
				participants.push_back(p);
			}
		}
		else if (choice == 2)
		{
			display_all_data(participants);
		}
		else if (choice == 3)
		{
			cin.ignore();
			string city;
			cout << "Write city: ";
			getline(cin, city);
			show_woman_participants_from_city(participants, city);
		}
		else if (choice == 4)
		{
			show_the_participant_with_the_most_points(participants);
		}
		else if (choice == 5)
		{
			show_student_with_the_most_points(participants);
		}
		else if (choice == 6)
		{
			cin.ignore(); 
			string uni;
			int current_year;

			cout << "Write university: ";
			getline(cin, uni);

			cout << "Enter current year for calculation (e.g. 2026): ";
			cin >> current_year;

			show_men_uni_students_higher_than_20_years_old_from_university(participants, uni, current_year);
		}
		else if (choice == 7)
		{
			cin.ignore();
			string uni;
			cout << "Write university: ";
			getline(cin, uni);
			show_women_university_students_above_50_points(participants, uni);
		}
		else if (choice == 8)
		{
			cin.ignore();
			string major;
			cout << "Write major: ";
			getline(cin, major);
			show_uni_students_from_major_with_more_25points(participants, major, 25.0);
		}
	} while (choice != 0);
	for (Participant* p : participants)
	{
		delete p;
	}
}
