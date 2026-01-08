// Да се състави програма с рекурсивни функции 
// за извеждане на цифрите на зададено цяло
// число в прав и обратен ред. 


#include <iostream>
using namespace std;

void print_reverse(int n)
{
	if (n == 0)
		return;
	cout << n % 10 << " ";
	print_reverse(n / 10);
}

int main()
{
	int n;
	cin >> n;
	print_reverse(n);
	return 0;
}
