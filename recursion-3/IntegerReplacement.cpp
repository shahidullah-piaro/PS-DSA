//https://leetcode.com/problems/integer-replacement/description/
#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, int> dp;

long long integerReplace(long long n) {
    if (n <= 1) {
        return 0;
    }

    if (dp.find(n) != dp.end()) {
        return dp[n];
    }

    if (n % 2 == 0) {
        return dp[n] = 1 + integerReplace(n / 2);
    }

    return dp[n] = 1 + min(integerReplace(n + 1), integerReplace(n - 1));
}

int main() {
    long long n;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Error: Input must be a positive integer." << endl;
        return 1; // Indicate error
    }

    int result = integerReplace(n);
    cout << "Minimum number of operations: " << result << endl;

    return 0;
}
