#include <iostream>
#include <string>
using namespace std;


struct Book {
	string title;
	string author;
	int pages;
};

int main()
{
	Book books[1000];
	int n;
	cout << "Enter how many books you want to write: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Enter the title: ";
		getline(cin, books[i].title);

		cout << "Enter the author: ";
		getline(cin, books[i].author);

		cout << "Pages: ";
		cin >> books[i].pages;
	}

	int longest_title_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (books[i].title.length() > books[longest_title_index].title.length())
			longest_title_index = i;
	}
	cout << "\nBook with the longest name: " << books[longest_title_index].title;
}
