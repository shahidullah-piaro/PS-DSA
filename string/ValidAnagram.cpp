//https://leetcode.com/problems/valid-anagram
#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
    // Handle cases where strings have different lengths
    if (s.length() != t.length()) {
        return false;
    }

    // Efficiently count character frequencies using a frequency array
    int count[26] = {0};
    for (char x : s) {
        count[tolower(x) - 'a']++; // Convert to lowercase for case-insensitive comparison
    }

    // Check if corresponding characters in t have the same frequency
    for (char x : t) {
        int index = tolower(x) - 'a';
        if (count[index] == 0) {
            return false; // Character in t not present in s
        }
        count[index]--;
    }

    // All characters have matched frequencies
    return true;
}

int main() {
    string s, t;

    cout << "Enter the first string: ";
    getline(cin, s); // Use getline to handle spaces

    cout << "Enter the second string: ";
    getline(cin, t);

    if (isAnagram(s, t)) {
        cout << "\"" << s << "\" and \"" << t << "\" are anagrams." << endl;
    } else {
        cout << "\"" << s << "\" and \"" << t << "\" are not anagrams." << endl;
    }

    return 0;
}

