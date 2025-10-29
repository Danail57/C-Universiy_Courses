# Зададени са точка с координатите си х и у и правоъгълник, ограничен от правите с уравнения х=0, y=0, x=A, y=B (A>0, B<0). 
# Да се състави алгоритъм и напише програма на С++ и да се определи дали точката лежи на правоъгълника.

#include <iostream>
using namespace std;

int main()
{
    double x, y, A, B;
    cout << "Enter the coordinates for x: ";
    cin >> x;
    
    cout << "Enter the coordinates for y: ";
    cin >> y;
    
    
    cout << "Enter A which is the Ox limit: ";
    cin >> A;
    
    cout << "Enter B which is the Oy limit: ";
    cin >> B;
    
    if (x == 0 || x == A || y == 0 || y == B) {
        cout << "The point is on the rectangle." << endl;
    } else {
        cout << "The point is not on the rectangle." << endl;
    }
    return 0;
}
