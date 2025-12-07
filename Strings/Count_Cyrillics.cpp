// Да се състави програма, която преброява
// главните букви в зададен символен низ, 
// съдържащ букви от кирилицата и
// препинателни знаци. 

#include <iostream>
#include <locale>

using namespace std;

int main()
{

	locale::global(locale(""));

	wstring text;
	wcout << L"Enter a text: ";
	getline(wcin, text);

	// char upper_cyrilic_chars;
	int count = 0;
	
	for (wchar_t s : text)
	{
		if (s >= L'А' && s <= L'Я')
		{
			count++;
		}
	}
	wcout << L"Number of uppercase Cyrillic letters: " << count << endl;
	return 0;
}
