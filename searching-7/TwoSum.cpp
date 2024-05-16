//https://leetcode.com/problems/two-sum/description/
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int, int> hashtable;
    vector<int> result;

    // Get input for array elements from the user
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    cout << "Enter the elements of the array (separated by spaces): ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // Implement the twoSum logic
    for (int i = 0; i < nums.size(); ++i) {
        int second_num = target - nums[i];
        if (hashtable.count(second_num) > 0) {
            result.push_back(i);
            result.push_back(hashtable[second_num]);
            break;
        }
        hashtable[nums[i]] = i;
    }

    return result;
}

int main() {
    int target;

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> nums;
    vector<int> indices = twoSum(nums, target);

    if (indices.empty()) {
        cout << "No two numbers in the array add up to the target sum." << endl;
    } else {
        cout << "The indices of the two numbers are: " << indices[0] << " and " << indices[1] << endl;
    }

    return 0;
}
