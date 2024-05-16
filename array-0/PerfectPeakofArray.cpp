//https://www.interviewbit.com/problems/perfect-peak-of-array/
#include <bits/stdc++.h>

using namespace std;

int perfectPeak(vector<int>& A) {
    int n = A.size();

    // Create vectors to store maximum from left and minimum from right
    vector<int> max_left(n);
    max_left[0] = A[0];
    for (int i = 1; i < n; ++i) {
        max_left[i] = max(A[i], max_left[i - 1]);
    }

    vector<int> min_right(n);
    min_right[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        min_right[i] = min(A[i], min_right[i + 1]);
    }

    // Check for perfect peak
    for (int i = 1; i < n - 1; ++i) {
        if (A[i] > max_left[i - 1] && A[i] < min_right[i + 1]) {
            return 1; // Found a perfect peak
        }
    }

    return 0; // No perfect peak found
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int result = perfectPeak(A);

    if (result) {
        cout << "The array contains a perfect peak." << endl;
    } else {
        cout << "The array does not contain a perfect peak." << endl;
    }

    return 0;
}
