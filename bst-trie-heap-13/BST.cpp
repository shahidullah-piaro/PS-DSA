//https://leetcode.com/problems/validate-binary-search-tree/description/
#include <bits/stdc++.h>

using namespace std;

// Structure to represent a tree node
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) {
    val = value;
    left = nullptr;
    right = nullptr;
  }
};

// Function to perform in-order traversal (LNR)
void LNR(TreeNode* root, vector<int>& vals) {
  if (root == nullptr) {
    return;
  }
  LNR(root->left, vals);
  vals.push_back(root->val);
  LNR(root->right, vals);
}

// Function to check if a binary tree is a valid BST
bool isValidBST(TreeNode* root) {
  vector<int> vals;
  LNR(root, vals);
  for (int i = 1; i < vals.size(); ++i) {
    if (vals[i] <= vals[i - 1]) {
      return false;
    }
  }
  return true;
}

// Function to get user input for tree creation
TreeNode* createTree() {
  int val;
  cout << "Enter the value for the node (enter -1 for null): ";
  cin >> val;

  if (val == -1) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(val);
  cout << "Enter value for left child of " << val << ": ";
  root->left = createTree();
  cout << "Enter value for right child of " << val << ": ";
  root->right = createTree();

  return root;
}

int main() {
  TreeNode* root = createTree();

  if (isValidBST(root)) {
    cout << "The tree is a valid BST." << endl;
  } else {
    cout << "The tree is not a valid BST." << endl;
  }

  return 0;
}

