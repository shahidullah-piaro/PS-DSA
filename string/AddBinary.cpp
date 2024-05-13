//https://leetcode.com/problems/add-binary
#include <bits/stdc++.h>

using namespace std;

string addBinary(string a, string b) {
    string res;
    int i = a.length() - 1, j = b.length() - 1;
    int carry = 0;

    // Handle strings with different lengths efficiently
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        // Add digits from a (if available)
        if (i >= 0) {
            if (a[i] != '0' && a[i] != '1') {
                // Input validation: handle invalid characters
                cerr << "Error: Invalid character '" << a[i] << "' in input string a." << endl;
                return ""; // Indicate error
            }
            sum += a[i--] - '0';
        }

        // Add digits from b (if available)
        if (j >= 0) {
            if (b[j] != '0' && b[j] != '1') {
                // Input validation: handle invalid characters
                cerr << "Error: Invalid character '" << b[j] << "' in input string b." << endl;
                return ""; // Indicate error
            }
            sum += b[j--] - '0';
        }

        carry = sum > 1 ? 1 : 0;
        res += to_string(sum % 2);
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a, b;

    cout << "Enter the first binary string (0s and 1s only): ";
    cin >> a;

    cout << "Enter the second binary string (0s and 1s only): ";
    cin >> b;

    string result = addBinary(a, b);

    if (result.empty()) {
        // Handle error if addBinary returned empty string
        cout << "Error: Invalid binary strings encountered." << endl;
    } else {
        cout << "The sum in binary is: " << result << endl;
    }

    return 0;
}

