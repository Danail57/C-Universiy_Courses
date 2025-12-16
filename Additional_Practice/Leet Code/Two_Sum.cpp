#include <iostream>
#include <vector>
using namespace std;

vector<int> two_sum(vector<int> & numbers, int target)
{
    int n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}


int main()
{
    vector<int>numbers;
    int x, n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        numbers.push_back(x);
    }
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int>result = two_sum(numbers, target);
    if (!result.empty())
    
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    else
        cout << "No solution found." << endl;
    
    return 0;
}
