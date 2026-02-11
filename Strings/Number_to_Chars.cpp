/*Напишете програма, която преобразува положително
 * цяло число в съответния му символен низ
 * чрез рекурсивна функция и да връща дължината
 * на низа
 *
 */
#include <iostream>
using namespace std;
unsigned int conventor(unsigned int x, char* num)
{
    if (x == 0)
        return 0;
    int pos = conventor(x / 10, num);
    num[pos] =  x % 10 + '0';
    return pos + 1;
}

int main()
{
    unsigned int number;
    cout << "Enter a positive number: ";
    cin >> number;

    char num[20];
    unsigned int len;
    if (number == 0) {
        num[0] = '0';
        len = 1;
    }
    else {
        len = conventor(number, num);
    }
    num[len] = '\0';
    cout << "String representation: " << num << endl;
    cout << "Length: " << len << endl;
    return 0;
}
