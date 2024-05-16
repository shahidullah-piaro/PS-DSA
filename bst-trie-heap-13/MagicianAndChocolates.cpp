//https://www.interviewbit.com/problems/magician-and-chocolates/
#include <bits/stdc++.h>

using namespace std;

int nchoc(int A, vector<int>& B) {
    long int sum = 0;
    make_heap(B.begin(), B.end());

    while(A--)
    {
        int max_value = B[0];
        sum = (sum + max_value) % 1000000007;
        pop_heap(B.begin(), B.end());
        B.pop_back();
        B.push_back((int)(max_value/2));
        push_heap(B.begin(), B.end());
    }

    return sum;
}

int main() {
    int A, N;

    cout << "Enter the value of A (positive integer): ";
    cin >> A;

    cout << "Enter the size of the vector B (positive integer): ";
    cin >> N;

    if (N <= 0) {
        cerr << "Invalid input: Size of B must be positive." << endl;
        return 1; // Indicate error
    }

    vector<int> B(N);
    cout << "Enter the elements of vector B (integers): ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    long long int result = nchoc(A, B);

    if (result != -1) { // Check if nchoc returned an error
        cout << "The sum is: " << result << endl;
    }

    return 0;
}

