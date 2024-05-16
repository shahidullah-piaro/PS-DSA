//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n;  // Number of elements
    int target;

    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    vector<int> nums(n);  // Create a vector of size n

    cout << "Enter the elements of the vector (sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target value to search: ";
    cin >> target;

    int index = search(nums, target);

    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found in the vector." << endl;
    }

    return 0;
}

