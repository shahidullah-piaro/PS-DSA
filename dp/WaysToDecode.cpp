//https://www.interviewbit.com/problems/ways-to-decode/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int numDecodings(string A) {
    int n = A.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    // Check if the first character is valid (non-zero)
    if (A[0] == '0') {
        return 0;
    }
    dp[1] = 1;

    for (int i = 1; i < n; i++) {
        // Handle single-digit cases
        if (A[i] != '0') {
            dp[i + 1] = dp[i];
        }

        // Handle double-digit cases (10 to 26)
        if (i > 0 && A[i - 1] == '1' || (A[i - 1] == '2' && A[i] <= '6')) {
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
        }

        // Check for invalid double-digit cases (leading zero or greater than 26)
        if (A[i] == '0' && (A[i - 1] > '2' || A[i - 1] < '1')) {
            return 0;
        }
    }

    return dp[n];
}

int main() {
    string A;
    cout << "Enter the encoded string: ";
    getline(cin, A); // Get entire line to handle spaces

    int numDecodingsResult = numDecodings(A);

    if (numDecodingsResult == 0) {
        cout << "Invalid string." << endl;
    } else {
        cout << "Number of decodings: " << numDecodingsResult << endl;
    }

    return 0;
}
