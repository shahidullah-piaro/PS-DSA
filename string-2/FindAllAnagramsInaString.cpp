//https://leetcode.com/problems/find-all-anagrams-in-a-string
#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p) {
        vector <int> v; // For storing the start index
        vector <int> v1(26,0); // Frequency of char in string s
        vector <int> v2(26,0); // Frequency of char in string p
        int m=s.size();
        int n=p.size();
        if(n>m)
            return v; // Impossible Case
        int left=0,right=0;
        for(int i=0;i<n;i++){ //Calculating freq of p and starting of string s
            v1[s[i]-'a']++;
            v2[p[i]-'a']++;
            right++;
        }
        right--;
        for(int i=right;i<m;i++){
            if(v1==v2)
                v.push_back(left); // If the anagram is found then adding the starting index to the ans vector 'v'
            right++;
            if(right!=m)
                v1[s[right]-'a']++; // Adding the freq of new added char in window

            v1[s[left]-'a']--; // Removing the freq of last char of the window while moving forward
            left++; // Left and Right are incremented to keep the sliding window moving forward
        }

        return v;// Returning the starting index's
    }

int main() {
    string s, p;
    cout << "Enter the string (s): ";
    getline(cin, s);
    cout << "Enter the pattern (p): ";
    getline(cin, p);

    vector<int> anagramIndices = findAnagrams(s, p);

    if (anagramIndices.empty()) {
        cout << "No anagrams found." << endl;
    } else {
        cout << "Anagram starting indices: ";
        for (int index : anagramIndices) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}

