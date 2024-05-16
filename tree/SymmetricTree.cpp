//https://leetcode.com/problems/symmetric-tree/description/
#include <bits/stdc++.h>

using namespace std;

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

// Function to check if two subtrees are symmetrical (recursive)
bool c(TreeNode* left, TreeNode* right) {
    if (!left || !right) {
        return left == right; // Both null or both non-null
    }

    if (left->val != right->val) {
        return false;
    }

    return c(left->left, right->right) && c(left->right, right->left);
}

// Function to check if the entire binary tree is symmetrical (wrapper)
bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true; // Empty tree is considered symmetric
    }

    return c(root->left, root->right);
}

// Function to create a binary tree node (helper for user input)
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

// Function to get user input for a binary tree (recursive)
TreeNode* getInputTree(TreeNode* root) {
    int data;
    cout << "Enter node value (-1 for null): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    root = createNode(data);

    cout << "Enter left child for " << data << ": ";
    root->left = getInputTree(root->left);

    cout << "Enter right child for " << data << ": ";
    root->right = getInputTree(root->right);

    return root;
}

int main() {
    TreeNode* root = nullptr;

    cout << "Create a binary tree:\n";
    root = getInputTree(root);

    if (isSymmetric(root)) {
        cout << "The binary tree is symmetrical.\n";
    } else {
        cout << "The binary tree is not symmetrical.\n";
    }

    return 0;
}

