#pragma once
#include "Document.h"

class StudentCard : public Document
{
public:
	string university;
	void get_data();
	void display();
};