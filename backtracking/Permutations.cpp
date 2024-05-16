//https://www.interviewbit.com/problems/permutations/
#include <bits/stdc++.h>

using namespace std;

void Permutation(vector<int> A, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& visited) {
    // Base Case: When the temporary vector reaches the same size as the input vector,
    // a permutation is complete. Add it to the answer vector.
    if (temp.size() == A.size()) {
        ans.push_back(temp);
        return;
    }

    // Traverse each element and check if it can be included in the permutation
    for (int i = 0; i < A.size(); i++) {
        // Check if the element has already been used
        if (visited[i] == false) {
            visited[i] = true; // Mark the element as used
            temp.push_back(A[i]); // Add element to the temporary vector

            Permutation(A, ans, temp, visited); // Recursive call to generate permutations

            visited[i] = false; // Backtrack: Unmark the element for other permutations
            temp.pop_back();     // Remove element from the temporary vector
        }
    }
}

vector<vector<int>> permute(vector<int>& A) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(A.size(), false);

    Permutation(A, ans, temp, visited);

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<vector<int>> permutations = permute(A);

    cout << "All permutations:" << endl;
    for (const vector<int>& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

