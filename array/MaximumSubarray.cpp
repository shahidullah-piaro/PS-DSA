//https://leetcode.com/problems/maximum-subarray
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int running_sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // Consider the current element or the sum of the current element and the previous subarray
        running_sum = max(nums[i], nums[i] + running_sum);

        // Update the maximum sum if the current subarray has a higher sum
        max_sum = max(max_sum, running_sum);
    }

    return max_sum;
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maximum_sum = maxSubArray(nums);

    cout << "The maximum subarray sum is: " << maximum_sum << endl;

    return 0;
}
