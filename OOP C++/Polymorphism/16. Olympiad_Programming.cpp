/*16. До участие в национална олимпиада по програмиране
се допускат студенти (име, ЕГН, университет, факултет, 
специалност, събрани точки) и
ученици (име, ЕГН, училище, клас, събрани точки). 
Данните за всички участници се съхраняват в един масив.
Да се състави програма, която изпълнява от меню следните операции:
- добавя към масива данните на пореден участник;
- извежда всички въведени данни;
- извежда данните на участничките от 
зададено населено място;
- създава масив с данните на всички 
участници мъже.*/

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

class Participant {
protected:
	string name;
	string EGN;
	string city;
	double points;

public:
	virtual ~Participant(){}
	virtual void get_data()
	{
		cin.ignore();
		cout << "Name: "; getline(cin, name);
		cout << "EGN: "; cin >> EGN;
		cin.ignore();
		cout << "Town: "; getline(cin, city);
		cout << "Points: "; cin >> points;
	}

	virtual void display()
	{
		cout << "Name: " << name << endl;
		cout << "EGN: " << EGN << endl;
		cout << "Town: " << city << endl;
		cout << "Points: " << points << endl;
	}

	virtual bool show_women_data_from_city(string city)
	{
		return false;
	}
	virtual bool is_from_city(string city)
	{
		return false;
	}

	virtual void print_all_men_data(){}
	virtual string getEGN() { return EGN; }
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

	bool show_women_data_from_city(string target_city)
	{
		return target_city == city;
	}

	bool is_from_city(string target_city)
	{
		return city == target_city;
	}
	

};

class Student : public Participant
{
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

	bool is_from_city(string target_city)
	{
		return city == target_city;
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
		if (p->is_from_city(city) && is_female(p->getEGN()))
		{
			p->display();
		}
	}
}


vector <Participant*> create_man_array(vector<Participant*> participants)
{
	vector<Participant*> men;
	for (Participant* p : participants)
	{
		if (is_male(p->getEGN()))
		{
			men.push_back(p);
		}
	}
	return men;
}

void display_all_men_data(vector<Participant*> participants)
{
	vector<Participant*> men = create_man_array(participants);
	for (Participant* p : men)
	{
		p->display();
	}
}


int main()
{
	vector<Participant*> participants;
	int choice;

	do {
		cout << "\nMENU (Task 16)\n";
		cout << "1. Add new participant\n";
		cout << "2. Display all data\n";
		cout << "3. Show all men data\n";
		cout << "4. Display woman participants from a city\n";
		cout << "5. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			int choice_num;
			cout << "Write (1 - Student, 2 - University student): "; cin >> choice_num;
			if (choice_num == 1)
			{
				Participant* p = new Student();
				p->get_data();
				participants.push_back(p);
			}
			else if (choice_num == 2)
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
			display_all_men_data(participants);
		}
		else if (choice == 4)
		{
			string target_city;
			cout << "Write city: ";
			cin.ignore();
			getline(cin, target_city);
			show_woman_participants_from_city(participants, target_city);
		}

	} while (choice != 5);
	for (Participant* p : participants)
	{
		delete p;
	}
}
