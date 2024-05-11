//https://www.interviewbit.com/problems/pick-from-both-sides/
#include <bits/stdc++.h>

using namespace std;

int maxSum(const vector<int>& A, int B) {
    int n = A.size();
    if (B > n) {
        return numeric_limits<int>::min(); // Handle invalid input (B > n)
    }

    int currSum = 0;
    for (int i = 0; i < B; i++) {
        currSum += A[i];
    }

    int maxSum = currSum;
    int inc = n - 1, exc = B - 1;
    while (inc >= 0 && exc >= 0) {
        currSum += A[inc];
        currSum -= A[exc];
        inc--;
        exc--;
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the vector (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int B;
    cout << "Enter the value of B: ";
    cin >> B;

    int result = maxSum(A, B);

    if (result == numeric_limits<int>::min()) {
        cout << "Invalid input: B cannot be greater than the size of the vector." << endl;
    } else {
        cout << "The maximum sum of a subarray of size B is: " << result << endl;
    }

    return 0;
}
