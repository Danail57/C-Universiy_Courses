/*Да се напише програма, която въвежда от 
клавиатурата два низа, несъдържащи интервали 
и определя може ли от знаците на първия низ да се
състави втория. Низовете се въвеждат от
клавиатурата, написани на един ред и 
разделени с поне един интервал.
Програмата да изведе на екрана съответно
“Yes” или “No”.*/



#include <iostream> 
#include <cstring>
using namespace std;

int main()
{
	char s1[1000], s2[1000];
	cin >> s1 >> s2;
	int count[256] = { 0 };

	for (int i = 0; s1[i] != '\0'; i++)
	{
		count[(unsigned char)s1[i]]++;
	}

	for (int i = 0; s2[i] != '\0'; i++)
	{
		if (count[(unsigned char)s2[i]] == 0);
		{
			cout << "No";
			return 0;
		}
		count[(unsigned char)s2[i]]--;
	}
	cout << "Yes";
	return 0;
}
