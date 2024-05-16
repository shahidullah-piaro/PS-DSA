//https://www.interviewbit.com/problems/majority-element/
#include <bits/stdc++.h>

using namespace std;

int majorityElement(const vector<int>& A) {
    int count = 0;
    int majority = A[0]; // Initialize with the first element

    for (int i = 1; i < A.size(); i++) {
        if (A[i] == majority) {
            count++;
        } else {
            count--;
            if (count < 0) { // Handle potential cancellation of majority candidate
                count = 0;
                majority = A[i]; // Update majority candidate if count becomes negative
            }
        }
    }

    // Final verification: Check if the candidate appears more than half the times
    count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == majority) {
            count++;
        }
    }

    if (count > A.size() / 2) {
        return majority;
    } else {
        return -1; // No majority element found
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int majority = majorityElement(A);

    if (majority != -1) {
        cout << "The majority element is: " << majority << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}

