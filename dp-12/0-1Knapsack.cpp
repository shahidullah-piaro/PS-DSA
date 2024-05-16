//https://www.interviewbit.com/problems/0-1-knapsack/
#include <bits/stdc++.h>

using namespace std;

int helper(vector<int>& a, vector<int>& b, int c, int n, vector<vector<int>>& dp) {
    if (n == 0 || c == 0) {
        return 0; // No elements or no capacity, return 0
    }

    if (dp[n][c] != -1) {
        return dp[n][c]; // Return pre-computed value to avoid redundant calculations
    }

    if (b[n - 1] <= c) {
        // Include the current element if it fits the capacity
        dp[n][c] = max(
            a[n - 1] + helper(a, b, c - b[n - 1], n - 1, dp), // Include current element
            helper(a, b, c, n - 1, dp) // Exclude current element
        );
    } else {
        // If the current element doesn't fit, exclude it
        dp[n][c] = helper(a, b, c, n - 1, dp);
    }

    return dp[n][c];
}

int solve(vector<int>& A, vector<int>& B, int C) {
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, -1)); // Initialize dp with -1 for memoization

    // Call helper function with proper arguments
    return helper(A, B, C, n, dp);
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> A(n), B(n);

    cout << "Enter the values for vector A:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter the costs for vector B:\n";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int C;
    cout << "Enter the target capacity: ";
    cin >> C;

    int result = solve(A, B, C);
    cout << "Maximum achievable value within capacity: " << result << endl;

    return 0;
}

