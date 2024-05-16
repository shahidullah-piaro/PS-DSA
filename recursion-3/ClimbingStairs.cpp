//https://leetcode.com/problems/climbing-stairs/description/
#include <bits/stdc++.h>

using namespace std;

// Function to calculate the number of ways to climb n stairs
int solve(int n, vector<int>& dp) {
    if (n < 0) {
        return 0; // No valid way to climb negative stairs
    } else if (n == 0) {
        return 1; // Standing at the bottom (0th stair) counts as 1 way
    }

    if (dp[n] != -1) {
        return dp[n]; // Return pre-calculated value for efficiency
    }

    // Calculate and store the number of ways for n stairs
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}

int main() {
    int n;

    cout << "Enter the number of stairs: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input: Number of stairs cannot be negative." << endl;
        return 1; // Indicate error
    }

    vector<int> dp(n + 1, -1); // Initialize dp vector with size n+1

    int numWays = solve(n, dp);
    cout << "The number of ways to climb " << n << " stairs: " << numWays << endl;

    return 0;
}

