//https://leetcode.com/problems/spiral-matrix-ii/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int counter = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        // Fill top row from left to right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = counter;
            counter++;
        }
        top++;

        // Fill right column from top to bottom (excluding already filled top row)
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = counter;
            counter++;
        }
        right--;

        // If there's more space to fill (bottom row not yet filled)
        if (top <= bottom) {
            // Fill bottom row from right to left
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = counter;
                counter++;
            }
            bottom--;
        }

        // If there's more space to fill (left column not yet filled after bottom row)
        if (left <= right) {
            // Fill left column from bottom to top (excluding already filled bottom row)
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = counter;
                counter++;
            }
            left++;
        }
    }

    return matrix;
}

int main() {
    int n;

    cout << "Enter the size of the matrix (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input: Matrix size must be positive." << endl;
        return 1; // Indicate error
    }

    vector<vector<int>> matrix = generateMatrix(n);

    cout << "Generated matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

