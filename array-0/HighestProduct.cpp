//https://www.interviewbit.com/problems/highest-product/
#include <bits/stdc++.h>

using namespace std;

int maxProductOfThree(vector<int>& A) {
    int size = A.size();

    // Sort the vector in ascending order to efficiently find the largest and smallest elements
    sort(A.begin(), A.end());

    // Calculate the product of the three largest elements
    int allPositives = A[size - 1] * A[size - 2] * A[size - 3];

    // Calculate the product of the first two smallest elements and the largest element
    // This handles the case where the largest element is negative
    int twoNegatives = A[0] * A[1] * A[size - 1];

    // Return the maximum of the two calculated products
    return max(allPositives, twoNegatives);
}

int main() {
    int n;

    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter the elements of the vector (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = maxProductOfThree(A);

    cout << "The maximum product of three numbers in the vector is: " << result << endl;

    return 0;
}
