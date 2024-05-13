//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
#include <bits/stdc++.h>

using namespace std;

int strStr(const string& haystack, const string& needle) {
    int n = haystack.size();
    int m = needle.size();

    // Handle empty needle case efficiently
    if (m == 0) {
        return 0;
    }

    // Efficiently iterate through haystack
    for (int i = 0; i <= n - m; i++) {
        // Check if first character matches
        if (haystack[i] == needle[0]) {
            bool flag = true;
            // Compare remaining characters, using a shorter loop
            for (int j = 1; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    string haystack, needle;

    cout << "Enter the haystack string: ";
    getline(cin, haystack);

    cout << "Enter the needle string: ";
    getline(cin, needle);

    int index = strStr(haystack, needle);

    if (index == -1) {
        cout << "Needle not found in haystack." << endl;
    } else {
        cout << "Needle found at index " << index << " in haystack." << endl;
    }

    return 0;
}
