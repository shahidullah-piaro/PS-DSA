//https://leetcode.com/problems/happy-number/description/
#include <bits/stdc++.h>

using namespace std;

int nextNumber(int n) {
    int newNumber = 0;
    while (n != 0) {
        int digit = n % 10; // Use 'digit' for better readability
        newNumber += digit * digit;
        n /= 10;
    }
    return newNumber;
}

bool isHappy(int n) {
    unordered_set<int> seenNumbers; // Use a more descriptive name
    while (n != 1 && seenNumbers.count(n) == 0) { // Check for existence before insertion
        seenNumbers.insert(n);
        n = nextNumber(n);
    }
    return n == 1;
}

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (number <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1; // Indicate error
    }

    if (isHappy(number)) {
        cout << number << " is a happy number." << endl;
    } else {
        cout << number << " is not a happy number." << endl;
    }

    return 0; // Indicate successful execution
}
