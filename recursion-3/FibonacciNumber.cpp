//https://leetcode.com/problems/fibonacci-number
#include <bits/stdc++.h>

using namespace std;

std::vector<int> memo;

int find_fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = find_fib(n - 1) + find_fib(n - 2);
    return memo[n];
}

int main() {
    int n;

    cout << "Enter a non-negative integer for Fibonacci calculation: ";
    cin >> n;

    if (n < 0) {
        cerr << "Error: Fibonacci is not defined for negative numbers." << endl;
        return 1; // Indicate error
    }

     // Pre-allocate memory for memoization table

    memo.assign(n + 1, -1);

    int result = find_fib(n);

    cout << "The nth Fibonacci number is: " << result << endl;

    return 0; // Indicate successful execution
}

