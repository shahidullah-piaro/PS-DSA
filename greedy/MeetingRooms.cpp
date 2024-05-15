//https://www.interviewbit.com/problems/meeting-rooms/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& A) {
    int n = A.size();
    vector<pair<int, int>> data; // Pre-allocate space for efficiency

    // Transform intervals into start/end points with +1/-1 values
    for (int i = 0; i < n; ++i) {
        data.push_back(make_pair(A[i][0], 1));
        data.push_back(make_pair(A[i][1], -1));
    }

    // Sort data by start time
    sort(data.begin(), data.end());

    int curr = 0;
    int ans = 0;
    for (const auto& [time, val] : data) {
        curr += val;
        ans = max(ans, curr);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(2)); // Create a 2D vector to store intervals

    cout << "Enter start and end for each interval (space-separated):\n";
    for (int i = 0; i < n; ++i) {
        cin >> A[i][0] >> A[i][1];
    }

    int max_overlap = solve(A);
    cout << "Maximum number of overlapping intervals: " << max_overlap << endl;

    return 0;
}

