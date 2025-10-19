
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


int main ()
{
    int count;
    cout << "How many numbers will you enter? ";
    cin >> count;
    vector<int> numbers;
int num;

cout << "Enter " << count << " numbers (separated by space): ";

cin.ignore();
string line;
getline(cin, line);
stringstream ss(line);

while (ss >> num) {
    numbers.push_back(num);
}

if (numbers.size() < count) {
    cout << "You entered fewer than " << count << " numbers!" << endl;
    return 1;
} else if (numbers.size() > count) {
    cout << "You entered more than " << count << " numbers!" << endl;
    return 1;
}
    
    sort(numbers.begin(), numbers.end());
    cout << "Numbers in ascending order: ";
    for (int num : numbers){
        cout << num << " ";
    }
    cout << endl;
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "Numbers in descending order: ";
    for (int num : numbers){
        cout << num << " ";
    }
    cout << endl;
    
    int min_num = *min_element(numbers.begin(), numbers.end());
    int max_num = *max_element(numbers.begin(), numbers.end());
    
    cout << "Minimum number: " << min_num << endl;
    cout << "Maximum number: " << max_num << endl;
    
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    
    double average = static_cast<double>(sum) / count;
    
    cout << "sum of numbers: " << sum << endl;
    cout << "Average of numbers: " << average << endl;
    
    int even_count = 0, odd_count = 0;
    for (int num : numbers) {
        if (num % 2 == 0)
            even_count += 1;
        else
        odd_count += 1;
    }
    
    cout << "Even numbers count: " << even_count << endl;
    cout << "Odd numbers count: " << odd_count << endl;
    
    return 0;
}
