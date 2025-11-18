// Да се състави алгоритъм, който за даден масив от цели числа
// намира индекса на елемента с най - голяма стойност;
// намира средното аритметично на четните числа в масива;
// намира средното аритметично на нечетните числа в масива;
// намира средното аритметично на положителните числа в масива;
// намира средното аритметично на отрицателните числа в масива.


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of the elements: ";
    cin >> n;

    int p[1000];

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> p[i];
    }

    //Намиране на най-голям елемент 
    int max_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i] > p[max_index])
        {
            max_index = i;
        }
    }

    
    double sum_even = 0, sum_odd = 0;
    double sum_pos = 0, sum_neg = 0;
    int count_even = 0, count_odd = 0;
    int count_pos = 0, count_neg = 0;

    for (int i = 0; i < n; i++) {
        // четни и нечетни
        if (p[i] % 2 == 0) {
            sum_even += p[i];
            count_even++;
        }
        else {
            sum_odd += p[i];
            count_odd++;
        }

        // положителни и отрицателни
        if (p[i] > 0) {
            sum_pos += p[i];
            count_pos++;
        }
        else if (p[i] < 0) {
            sum_neg += p[i];
            count_neg++;
        }
    }

    
    cout << fixed << setprecision(2);

    
    cout << "Index of largest element: " << max_index
        << " (value = " << p[max_index] << ")\n\n";

    if (count_even > 0)
        cout << "Average of even numbers: " << sum_even / count_even << endl;
    else
        cout << "No even numbers.\n";

    if (count_odd > 0)
        cout << "Average of odd numbers: " << sum_odd / count_odd << endl;
    else
        cout << "No odd numbers.\n";

    if (count_pos > 0)
        cout << "Average of positive numbers: " << sum_pos / count_pos << endl;
    else
        cout << "No positive numbers.\n";

    if (count_neg > 0)
        cout << "Average of negative numbers: " << sum_neg / count_neg << endl;
    else
        cout << "No negative numbers.\n";

    return 0;
}
