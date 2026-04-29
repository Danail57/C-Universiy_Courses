#include "Date.h"
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

void Date::display() 
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