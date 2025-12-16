#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m; 
        for (int i = 0; i < nums.size; i++)
        {
            int complement = target - nums[i];
            if(m.find(complement) != m.end())
                return {m[complement], i};
            m[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    int target, x, n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int>nums;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    cout << "Enter the target sum: ";
    cin >> target;
    Solution sol;
    vector<int>result = sol.Solution(nums, target);
    if(!reult.empty())
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    else
        cout << "No solution found." << endl;
    return 0;
}
