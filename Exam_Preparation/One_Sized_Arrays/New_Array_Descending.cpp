/* Дадени са променливата q и едномерният масив a с n
елемента, наредени в низходящ ред. Да се създаде нов масив b
с още един елемент, т. е. броят на елементите на b да стане
m=n+1. Стойността на допълнителния елемент да бъде q, а
мястото му да се определи така, че новият масив b също да е
нареден в низходящ ред.*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the count of elements: ";
    cin >> n;

    int A[100];
    cout << "\nEnter elements in descending order:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int q;
    cout << "Enter the new elements for the new array: ";
    cin >> q;

    int B[101];
    int index = 0;
    cout << "\nEnter elements in descending order: ";
    for (int i = 0; i < n + 1; i++)
    {
        if (A[i] > q)
        {
            B[index] = A[i];
            index++;
        }
        else
        {
            break;
        }
    }
    B[index] = q;
    index++;
    for (int i = index - 1; i < n; i++)
    {
        B[index] = A[i];
        index++;
    }
    cout << "\nNew array B in descending array order:\n";
    for (int i = 0; i < n + 1; i++)
    {
        cout << B[i] << " ";
    }
    return 0;
}
