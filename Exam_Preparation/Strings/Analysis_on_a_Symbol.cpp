/*Зададен е символен низ S, който съдържа от 1 до 30
думи(всяка дума се състои от не повече от 5 големи
	или малки латински букви), разделени с една
	или повече шпации(интервали).
	Да се напише програма, която: 
а) намира броя на думите които съдържат символа ’а’; 
б) преобразува всяка дума, която съдържа ’ks’, 
като заменя ’ks’ с ’х’; 
в) намира номера на най - дългата дума; 
г) извежда думите от S, но в обратен ред; 
д) извежда думите от S като 
изключва повтарящите се; 
е) извежда всички думи, 
които се срещат в точно по един път; 
ж) определя по колко пъти се среща всяка дума в S.*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char S[256];
	cout << "Enter string: ";
	cin.getline(S, 256);

	char words[30][6];
	int word_count = 0;
	int len = strlen(S);
	int position = 0;

	for (int i = 0; i <= len; i++)
	{
		if (S[i] != ' ' && S[i] != '\0')
		{
			if (position < 5)
			{
				words[word_count][position++] = S[i];
			}
		}
		else {
			if (position > 0)
			{
				words[word_count][position] = '\0';
				word_count++;
				position = 0;
			}
		}
	}
	int count_a = 0;
	for (int i = 0; i < word_count; i++)
	{
		for (int j = 0; words[i][j] != '\0'; j++)
		{
			if (words[i][j] == 'a')
			{
				count_a++;
				break;
			}
		}
	}
	cout << "Words with 'a': " << count_a << endl;

	for (int i = 0; i < word_count; i++)
	{
		for (int j = 0; words[i][j + 1] != '\0'; j++)
		{
			if (words[i][j] == 'k' && words[i][j + 1] == 's')
			{
				words[i][j] = 'x';
				int k = j + 1;
				while (words[i][k] != '\0')
				{
					words[i][k] = words[i][k + 1];
					k++;
				}
			}
		}
	}

	cout << "After replacing 'ks' with 'x': ";
	for (int i = 0; i < word_count; i++)
	{
		cout << words[i] << " ";
	}
	cout << endl;

	int max_len = 0;
	int max_index = 0;
	for (int i = 0; i < word_count; i++)
	{
		int l = strlen(words[i]);
		if (l > max_len)
		{
			max_len = l;
			max_index = i;
		}
	}
	cout << "Longest word index: " << max_index + 1 << endl;

	cout << "Words in reverse order: ";
	for (int i = word_count - 1; i >= 0; i--)
	{
		cout << words[i] << " ";
	}
	cout << endl;

	cout << "Unique words: ";
	for (int i = 0; i < word_count; i++)
	{
		bool duplicate = false;
		for (int j = 0; j < i; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
			{
				duplicate = true;
				break;
			}
		}
		if (!duplicate) cout << words[i] << " ";
	}
	cout << endl;

	cout << "Words appearing exactly once: ";
	for (int i = 0; i < word_count; i++)
	{
		int occurences = 0;
		for (int j = 0; j < word_count; j++)
		{
			if (strcmp(words[i], words[j]) == 0) occurences++;
		}
		if (occurences == 1) cout << words[i] << " ";
	}
	cout << endl;

	cout << "Word frequencies: ";
	for (int i = 0; i < word_count; i++)
	{
		bool printed = false;
		for (int j = 0; j < i; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
			{
				printed = true;
				break;
			}
		}
		if (!printed)
		{
			int occurences = 0;
			for (int j = 0; j < word_count; j++)
			{
				if (strcmp(words[i], words[j]) == 0) occurences++;
			}
			cout << words[i] << ":" << occurences << " ";
		}
	}
	cout << endl;
	return 0;
}
