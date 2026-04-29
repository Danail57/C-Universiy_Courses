#pragma once
#include "Document.h"

class LibraryCard : public Document {
public:
	int books_taken;

	void get_data() override;
	void display() override;
};