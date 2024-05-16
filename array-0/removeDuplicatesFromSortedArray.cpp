//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return n;  // No duplicates to remove for arrays with 0 or 1 element
    }

    int j = 0;  // Index for the unique elements
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[j]) {
            nums[++j] = nums[i];  // Shift unique elements
        }
    }

    return j + 1;  // Return the new length of the array with duplicates removed
}

int main() {
    int numElements;

    cout << "Enter the number of elements in the vector: ";
    cin >> numElements;

    vector<int> nums(numElements);

    cout << "Enter the elements of the vector (separated by spaces): ";
    for (int i = 0; i < numElements; i++) {
        cin >> nums[i];
    }

    int newLength = removeDuplicates(nums);

    cout << "The vector after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

