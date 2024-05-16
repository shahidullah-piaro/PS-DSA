//https://leetcode.com/problems/implement-trie-prefix-tree/description/
#include <bits/stdc++.h>

using namespace std;

// Trie node structure
struct TrieNode {
  char val;
  bool isEndOfWord;
  vector<TrieNode*> children;

  TrieNode(char val) : val(val), isEndOfWord(false), children(26, nullptr) {}
};

class Trie {
 private:
  TrieNode* root;

 public:
  Trie() {
    root = new TrieNode('\0');
  }

  // Insert a word into the trie
  void insert(const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
      int idx = c - 'a';
      if (curr->children[idx] == nullptr) {
        curr->children[idx] = new TrieNode(c);
      }
      curr = curr->children[idx];
    }
    curr->isEndOfWord = true;
  }

  // Search for a word in the trie
  bool search(const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
      int idx = c - 'a';
      if (curr->children[idx] == nullptr) {
        return false;
      }
      curr = curr->children[idx];
    }
    return curr->isEndOfWord;
  }

  // Check if a prefix exists in the trie
  bool startsWith(const string& prefix) {
    TrieNode* curr = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (curr->children[idx] == nullptr) {
        return false;
      }
      curr = curr->children[idx];
    }
    return true;
  }
};

int main() {
  Trie trie;
  trie.insert("apple");
  trie.insert("ape");
  trie.insert("application");

  cout << "Search 'apple': " << trie.search("apple") << endl;
  cout << "Search 'app': " << trie.search("app") << endl;
  cout << "Starts with 'ap': " << trie.startsWith("ap") << endl;

  return 0;
}
