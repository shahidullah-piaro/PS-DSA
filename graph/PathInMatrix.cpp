//https://www.interviewbit.com/problems/path-in-matrix/
#include <bits/stdc++.h>

using namespace std;

bool checkPath(vector<vector<int>> &a) {
    int n = a.size();

    // Validate input matrix dimensions (all rows should have the same number of columns)
    for (int i = 0; i < n; ++i) {
        if (a[i].size() != n) {
            cerr << "Error: Invalid input matrix. All rows must have the same number of columns." << endl;
            return false;
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    // Find starting point (cell with value 1)
    int start_i, start_j;
    bool found_start = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                start_i = i;
                start_j = j;
                found_start = true;
                vis[i][j] = true;  // Mark starting point as visited
                q.push({i, j});
                break;
            }
        }
        if (found_start) {
            break;
        }
    }

    if (!found_start) {
        cerr << "Error: No starting point (cell with value 1) found in the matrix." << endl;
        return false;
    }

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (a[i][j] == 2) {
            return true;  // Reached the ending point (cell with value 2)
        }

        // Check valid neighbors (within bounds and not visited)
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] != 0) {
            vis[i - 1][j] = true;
            q.push({i - 1, j});
        }
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] != 0) {
            vis[i + 1][j] = true;
            q.push({i + 1, j});
        }
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] != 0) {
            vis[i][j + 1] = true;
            q.push({i, j + 1});
        }
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] != 0) {
            vis[i][j - 1] = true;
            q.push({i, j - 1});
        }
    }

    return false; // No path found from starting point (1) to ending point (2)
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    cout << "Enter the elements of the matrix (1 for starting point, 2 for ending point, 0 for walls):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    if (checkPath(a)) {
        cout << "There exists a path from the starting point to the ending point." << endl;
    } else {
        cout << "There is no path from the starting point to the ending point." << endl;
    }

    return 0;
}
