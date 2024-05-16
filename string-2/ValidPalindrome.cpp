//https://leetcode.com/problems/valid-palindrome
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(str[left])) {
            left++;
        }

        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(str[right])) {
            right--;
        }

        // Check for palindrome characters (case-insensitive)
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string input;

    cout << "Enter a string to check for palindrome: ";
    getline(cin, input);  // Use getline to handle spaces

    if (isPalindrome(input)) {
        cout << input << " is a palindrome." << endl;
    } else {
        cout << input << " is not a palindrome." << endl;
    }

    return 0;
}
