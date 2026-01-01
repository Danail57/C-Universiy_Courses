/*цялостна програма за егн - да определя кой е мъж,
кой жена, да създаде нови масиви с егн-та та на
мъже само и на жени, определяне от тия масиви 
кой е най-млад от мъжете и кой стар, 
съответнно и за жените коя е най-млада и
коя най-стара, извеждане на датите,
месеца и годината кой кога е роден,
и да гледа дали има родени на една съща дата, 
месец или година,*/

#include <iostream>
#include <string>
using namespace std;

struct Person {
	string egn;
	int day;
	int month;
	int year;
	char gender;
};

char get_gender(const string& egn)
{
	int gender_digit = egn[8] - '0';
	if (gender_digit % 2 == 0)
		return 'M';
	else
		return 'F';
}

void get_birth_date(const string& egn, int& day, int& month, int& year)
{
	int yy = stoi(egn.substr(0, 2));
	int mm = stoi(egn.substr(2, 2));
	int dd = stoi(egn.substr(4, 2));

	if (mm >= 1 && mm <= 12)
	{
		year = 1900 + yy;
		month = mm;
	}
	else if (mm >= 21 && mm <= 32)
	{
		year = 1800 + yy;
		month = mm - 20;
	}
	else if (mm >= 41 && mm <= 52)
	{
		year = 2000 + yy;
		month = mm - 40;
	}
	day = dd;
}

bool is_younger(const Person& p1, const Person& p2)
{
	if (p1.year != p2.year)
		return p1.year > p2.year;
	if (p1.month != p2.month)
		return p1.month > p2.month;
	return p1.day > p2.day;
}

void print_person(const Person& p)
{
	cout << "EGN: " << p.egn << " | Gender: " << (p.gender == 'M' ? "Male" : "Female") << " | Born: " << p.day << "." << p.month << "." << p.year << endl;
}

int main()
{
	int n;
	cout << "Enter the number of people: ";
	cin >> n;

	Person people[1000];
	Person men[1000];
	Person women[1000];
	int men_count = 0, women_count = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter EGN: ";
		cin >> people[i].egn;

		people[i].gender = get_gender(people[i].egn);
		get_birth_date(people[i].egn,
			people[i].day,
			people[i].month,
			people[i].year);

		if (people[i].gender == 'M')
			men[men_count++] = people[i];
		else
			women[women_count++] = people[i];
	}
	if (men_count > 0)
	{
		int youngest = 0, oldest = 0;
		for (int i = 1; i < men_count; i++)
		{
			if (is_younger(men[i], men[youngest]))
				youngest = i;
			if (is_younger(men[oldest], men[i]))
				oldest = i;
		}
		cout << "\nYoungest man:\n";
		print_person(men[youngest]);

		cout << "\nOldest man:\n";
		print_person(men[oldest]);
	}
	if (women_count > 0)
	{
		int youngest = 0, oldest = 0;
		for (int i = 1; i < women_count; i++)
		{
			if (is_younger(women[i], women[youngest]))
				youngest = i;
			if (is_younger(women[oldest], women[i]))
				oldest = i;
		}
		cout << "\nYoungest woman:\n";
		print_person(women[youngest]);

		cout << "Oldest woman:\n";
		print_person(women[oldest]);
	}
	return 0;

}
