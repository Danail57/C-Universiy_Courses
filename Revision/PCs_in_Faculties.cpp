// pregovor_3.cpp 
// 3. k - faculties and n - PC rooms; for every room is known the count of computers
// and to which faculty belong to; show the count of the computers of every faculty


#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int k_faculties;
	cout << "Write how many faculties are in university: ";
	cin >> k_faculties;

	int rooms;
	cout << "Number of rooms: ";
	cin >> rooms;

	unordered_map<int, int> faculty_computers;
	// 1. int -> faculty number
	// 2. int -> total count of PCs

	for (int i = 0; i < rooms; i++)
	{
		int faculty_id, computers;
		cout << "Room " << i + 1 << " faculty number and PCs count: ";
		cin >> faculty_id >> computers;
		faculty_computers[faculty_id] += computers;
	}
	cout << "Total PCs in faculties: " << endl;
	for (auto pair : faculty_computers)
	{
		cout << "Faculty " << pair.first << ": " << pair.second << " PCs" << endl;
	}
}
