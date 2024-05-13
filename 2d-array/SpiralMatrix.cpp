//https://leetcode.com/problems/spiral-matrix
#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;

    // Handle empty matrix case
    if (matrix.empty() || matrix[0].empty()) {
        return result;
    }

    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;

    while (left <= right && top <= bottom) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        top++;  // Move top boundary for next iteration

        // Traverse from top to bottom (excluding already visited elements)
        if (top <= bottom) {
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;  // Move right boundary for next iteration
        }

        // Traverse from right to left (excluding already visited elements)
        if (left <= right && top <= bottom) {
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;  // Move bottom boundary for next iteration
        }

        // Traverse from bottom to top (excluding already visited elements)
        if (left <= right && top < bottom) {
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            left++;  // Move left boundary for next iteration
        }
    }

    return result;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> spiral = spiralOrder(matrix);

    cout << "Spiral order traversal: ";
    for (int num : spiral) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
