#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
CDate::CDate(){
	day = 1; month = 1; year = 1900;
}

CDate::CDate(short int d, short int m, short int y){
	day = d; month = m; year = y;
}

void CDate::enterDate(){
    cout<< "day: "; cin >>day;
	cout<< "month: "; cin >>month;
	cout<< "year: "; cin >>year;
}

void CDate::display(){
    cout<< day << "." << month << "." << year << endl;
}
string CDate::toString()
{
    stringstream ss;

    ss << day << "." 
       << month << "." 
       << year;

    return ss.str();
}

void CDate::setToCurrentDate(){
	time_t now;
	struct tm datetime;
	now = time(NULL);
	localtime_s(&datetime, &now);
//	datetime = *localtime(&now); // depricated in VS 2022
	day = datetime.tm_mday;
	month = datetime.tm_mon + 1;
	year = datetime.tm_year + 1900;
}

bool CDate::operator==(CDate date2){
	if(day == date2.day && month == date2.month && year == date2.year)
		return true;
	else
		return false;
	//return (day == date2.day) && (month == date2.month) && (year == date2.year);
}

short int CDate::getDay(){return day;}
short int CDate::getMonth(){return month;}
short int CDate::getYear(){return year;}
