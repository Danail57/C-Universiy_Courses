#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Document
{
public:
    string name;
    int document_number;
    Date issue_date;

    virtual void get_data();
    virtual void display();
    virtual Date valid_until() const;
};