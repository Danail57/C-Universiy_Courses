#pragma once
#include <string>
using namespace std;
class CDate {
private:
	unsigned short int day, month, year;
public:
	CDate();
	CDate(short int, short int, short int);
	void enterDate();
	void display();
	string toString();
	void setToCurrentDate();
	short int getDay();
	short int getMonth();
	short int getYear();
	bool operator==(CDate d);
	bool operator>(CDate d);
};

