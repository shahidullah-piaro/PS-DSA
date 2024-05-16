//https://leetcode.com/problems/valid-parentheses/description/
#include <bits/stdc++.h>


using namespace std;

bool isValid(string s) {
    stack<char> helper;

    for (char c : s) {
        switch (c) {
            case ')':
                if (helper.empty() || helper.top() != '(') {
                    return false;
                }
                helper.pop();
                break;
            case '}':
                if (helper.empty() || helper.top() != '{') {
                    return false;
                }
                helper.pop();
                break;
            case ']':
                if (helper.empty() || helper.top() != '[') {
                    return false;
                }
                helper.pop();
                break;
            default:
                helper.push(c); // Push opening brackets for later matching
        }
    }

    return helper.empty(); // Check for balanced brackets at the end
}

int main() {
    string input;

    cout << "Enter a string containing parentheses, braces, or brackets: ";
    getline(cin, input); // Use getline to handle spaces

    if (isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}

