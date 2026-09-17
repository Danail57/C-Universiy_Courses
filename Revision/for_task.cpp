// програма, в която потребителят 
// въвежда списък от думи. Програмата трябва 
// да преброи колко пъти се среща 
// всяка една дума и да изведе резултата.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int count_words(vector<string> words_arr)
{
	int n = words_arr.size();
	if (n == 0)
	{
		cout << "No words written" << endl;
		return;
	}
	for (string word : words_arr)

}



void print_array(unordered_map<int, string> fruits)
{
	for (auto element : fruits)
	{
		cout << element.first << " - " << element.second << endl;
	}
	cout << endl;
}

int main()
{

}
