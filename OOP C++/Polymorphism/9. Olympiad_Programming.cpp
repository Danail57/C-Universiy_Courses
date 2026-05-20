/*9. До участие в национална олимпиада по
програмиране се допускат студенти
(име, ЕГН, университет, факултет, специалност, събрани точки) 
иученици (име, ЕГН, училище, клас, събрани точки). 
Данните за всички участници
се съхраняват в масив, направете меню, 
което да изпълнява следните операции
- добавя данните на пореден участник
- извежда всички данни
- извежда данните на студентките 
от даден университет с повече от 50 точки
- създава масив с данните на всички ученици от
зададено населено място*/


// with polymorphism and inheritance


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


class Participant {
protected:
	string name;
	string EGN;
	double points;

public:
	virtual ~Participant(){}
	virtual void get_data() = 0;
	virtual void display_data() = 0;

	virtual bool show_women_university_students_above_50_points(string university)
	{
		return false;
	}

	virtual bool is_from_city(string city)
	{
		return false;
	}
};



class UniversityStudent : public Participant {
private:
	string university;
	string faculty;
	string speciality;

public:
	virtual void get_data() override;
	virtual void display_data() override;

	bool show_women_university_students_above_50_points(string uni) override
	{
		return university == uni && points > 50 && is_female(EGN);
	}
};



class Student : public Participant {
private:
	string school;
	double grade;
	string city;

public:
	virtual void get_data() override;
	virtual void display_data() override;

	bool is_from_city(string c) override
	{
		return city == c;
	}
};


void UniversityStudent::get_data()
{
	cin.ignore(); 
	cout << "Name: "; getline(cin, name);
	cout << "EGN: "; cin >> EGN;
	cin.ignore(); 
	cout << "University: "; getline(cin, university);
	cout << "Faculty: "; getline(cin, faculty); 
	cout << "Major: "; getline(cin, speciality);
	cout << "Points: "; cin >> points;
}

void UniversityStudent::display_data()
{
	cout << "Name: " << name << endl;
	cout << "EGN: " << EGN << endl;
	cout << "University: " << university << endl;
	cout << "Major: " << speciality << endl;
	cout << "Points: " << points << endl;
}


void Student::get_data()
{
	cin.ignore(); 
	cout << "Name: "; getline(cin, name);
	cout << "EGN: "; cin >> EGN;
	cin.ignore(); 
	cout << "School: "; getline(cin, school);
	cout << "Grade: "; cin >> grade;
	cin.ignore();  
	cout << "City: "; getline(cin, city);
	cout << "Points: "; cin >> points;
}

void Student::display_data()
{
	cout << "Name: " << name << endl;
	cout << "EGN: " << EGN << endl;
	cout << "School: " << school << endl;
	cout << "Grade: " << grade << endl;
	cout << "City: " << city << endl;
	cout << "Points: " << points << endl;
}


//полиморфизмът работи чрез базов клас указател => ползваме class Participant

void display_all_data_for_university_students(vector<Participant*> participants)
{
	for (Participant* p : participants)
	{
		p->display_data();
	}
}


void show_women_university_students_above_50_points(vector <Participant*> woman_university_student, string university)
{
	for (Participant* p : woman_university_student)
	{
		if (p->show_women_university_students_above_50_points(university))
		{
			p->display_data();
		}
	}
}

void show_students_from_city(vector <Participant*> participants, string city)
{
	for (Participant* p : participants)
	{
		if (p->is_from_city(city))
		{
			p->display_data();
		}
	}
}


int main()
{
	vector <Participant*> participants;
	int choice;

	do
	{
		cout << "\nMENU\n";
		cout << "1. Add university student\n";
		cout << "2. Add school student\n";
		cout << "3. Show all participants\n";
		cout << "4. Show women university students > 50.0 points\n";
		cout << "5. Show students from city\n";
		cout << "6. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			Participant* p = new UniversityStudent();
			p->get_data();
			participants.push_back(p);
		}
		else if (choice == 2)
		{
			Participant* p = new Student();
			p->get_data();
			participants.push_back(p);
		}
		else if (choice == 3)
		{
			for (Participant* p : participants)
			{
				p->display_data();
			}
		}
		else if (choice == 4)
		{
			string university;
			cin.ignore();
			cout << "Write university: ";
			getline(cin, university);

			for (Participant* p : participants)
			{
				if (p->show_women_university_students_above_50_points(university))
				{
					p->display_data();
				}
			}
		}
		else if (choice == 5)
		{
			string city;
			cin.ignore();
			cout << "Write city: "; getline(cin, city);
			for (Participant* p : participants)
			{
				if (p->is_from_city(city))
				{
					p->display_data();
				}
			}
		}
	} while (choice != 6);

	for (Participant* p : participants)
	{
		delete p;
	}
	return 0;
}
