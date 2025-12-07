// Да се състави програма, която преброява
// изреченията в зададен зададен символен низ,
// като се има предвид, че изреченията завършват
// с точка, въпросителен знак или удивителен знак.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string symbol_niz;
	cout << "Enter a text: ";
	getline(cin, symbol_niz);

	char sentence_symbols[] = {'.','?', '!'};

	int count_sentence_symbols = 0;
	for (char c : symbol_niz)
	{
		if (c == '.' || c == '?' || c == '!')
		{
			count_sentence_symbols++;
		}
	}
	if (count_sentence_symbols == 0)
	{
		cout << "No sentences found. A sentence must end with '.', '?' or '!'." << endl;
	}
	else
	{
		cout << "Number of sentences: " << count_sentence_symbols << endl;
	}
}
