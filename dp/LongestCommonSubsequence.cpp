//https://www.interviewbit.com/problems/longest-common-subsequence/
#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string A, string B) {
    int n = A.length();
    int m = B.length();

    // Create a 2D DP table to store LCS lengths
    int dp[n + 1][m + 1];

    // Initialize first row and column to 0 (base cases)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    // Fill the DP table using the LCS logic
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Match: add 1 to LCS
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // No match: take max LCS
            }
        }
    }

    return dp[n][m]; // Return the LCS length from the bottom-right corner
}

int main() {
    string A, B;

    cout << "Enter string A: ";
    getline(cin, A); // Get entire line to handle spaces

    cout << "Enter string B: ";
    getline(cin, B);

    int lcs = longestCommonSubsequence(A, B);

    cout << "The Longest Common Subsequence length is: " << lcs << endl;

    return 0;
}
