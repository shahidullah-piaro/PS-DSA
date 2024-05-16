//https://leetcode.com/problems/contains-duplicate
#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> seen;  // Use a more descriptive name for clarity

    for (int num : nums) {
        if (seen.count(num)) {  // Check if the element already exists using count()
            return true;
        }
        seen[num] = true;  // Insert the element and its existence flag
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size. Please enter a positive integer.\n";
        return 1;  // Indicate error
    }

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (containsDuplicate(nums)) {
        cout << "The array contains duplicate elements.\n";
    } else {
        cout << "The array does not contain duplicate elements.\n";
    }

    return 0;
}

