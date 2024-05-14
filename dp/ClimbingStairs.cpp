//https://www.interviewbit.com/problems/climbing-stairs/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& A) {
    int n = A.size();

    // Handle edge cases for array size less than 2 (return 0 for invalid input)
    if (n < 2) {
        return 0;
    }

    vector<int> sum(n);
    sum[0] = A[0];

    // Initialize sum[1] with minimum possible value for valid scenarios
    sum[1] = min(A[0] + A[1], numeric_limits<int>::max());

    for (int i = 2; i < n; i++) {
        sum[i] = min(A[i] + sum[i - 1], A[i] + sum[i - 2]);
    }

    return sum[n - 1];
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid array size (must be non-negative)." << endl;
        return 1;
    }

    vector<int> A(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = solve(A);
    cout << "The minimum sum to reach the last element is: " << result << endl;

    return 0;
}
