

/*9) Даден е двумерен масив А с m реда и n стълба. Да се състави
програма, която създава нов масив а0, а1,...,аm-1, като стойността на
аi е равна на средно-аритметичното на отрицателните елементи в
i-ия ред.
*/

#include <iostream>
using namespace std;

int main()
{
   int m;
   cout << "Enter the number of rows: ";
   cin >> m;

   int n;
   cout << "Enter the number of columns: ";
   cin >> n;

   int A[45][45];
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         cout << "A[" <<i + 1<< "][" << j + 1 << "]: ";
         cin >> A[i][j];
      }
   }
   int new_array[100];
   for (int i = 0; i < m; i++) {
      int sum_negative = 0;
      int count_negative = 0;

      for (int j = 0; j < n; j++) {
         if (A[i][j] < 0) {
            sum_negative += A[i][j];
            count_negative++;
         }
      }
      if (count_negative > 0) {
         new_array[i] = (double)sum_negative / count_negative;
      }
      else {
         new_array[i] = 0;
      }
   }
   cout << "New array: " << endl;
   for (int i = 0; i < m; i++) {
      cout << "New array["<< i + 1 <<"] = " << new_array[i] << endl;
   }
}
