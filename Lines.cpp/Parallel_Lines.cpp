/*27) how to check if two lines are parallel*/

#include <iostream> 
#include <cmath>
using namespace std;

void parallel(float a1, float b1, float c1, float a2, float b2, float c2)
{
	if (a1 * b2 == a2 * b1)
	{
		cout << "Yes, lines are parallel" << endl;
	}
	else
	{
		cout << "No, lines are not parallel" << endl;
	}
}

struct Line {
	float A, B, C;
};

int main()
{
	int m;
	cout << "Enter the number of lines: ";
	cin >> m;
	Line lines[1000];
	for (int i = 0; i < m; i++)
	{
		cout << "Enter line " << i + 1 << " coeff (A, B, C ): ";
		cin >> lines[i].A >> lines[i].B >> lines[i].C;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			cout << "Line " << i + 1 << " and line " << j + 1 << ": ";
			parallel(lines[i].A, lines[i].B, lines[i].C, lines[j].A, lines[j].B, lines[j].C);
		}
	}
}
