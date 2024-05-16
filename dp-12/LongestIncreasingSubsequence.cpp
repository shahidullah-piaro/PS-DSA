//https://www.interviewbit.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lis(const vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1); // Initialize dp array with 1s for base cases

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]); // Update dp[i] if a[i] is greater than a[j]
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); // Find the maximum value in dp
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solution sol; // Create an object of Solution class
    int length = sol.lis(a);
    cout << "The length of the longest increasing subsequence is: " << length << endl;

    return 0;
}

