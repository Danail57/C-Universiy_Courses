#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Date {
public:
	int day, month, year;
	void get_data();
	void display();

    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator!=(const Date& other) const;

    Date operator+(int days) const;
};
Date current_date();