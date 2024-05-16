//https://leetcode.com/problems/same-tree/description/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

// Function to create a binary tree node (helper for user input)
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

// Function to take user input for a binary tree (recursive)
TreeNode* userInputTree(TreeNode* root) {
    int value;
    cout << "Enter node value (-1 for null): ";
    cin >> value;

    if (value == -1) {
        return nullptr;
    }

    root = createNode(value);
    root->left = userInputTree(root->left);
    root->right = userInputTree(root->right);

    return root;
}

// Function to check if two binary trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }

    queue<TreeNode*> nodes;
    nodes.push(p);
    nodes.push(q);

    while (!nodes.empty()) {
        TreeNode* t1 = nodes.front();
        nodes.pop();
        TreeNode* t2 = nodes.front();
        nodes.pop();

        if (t1 == NULL && t2 == NULL) {
            continue;
        }
        if (t1 == NULL || t2 == NULL || t1->val != t2->val) {
            return false;
        }

        nodes.push(t1->left);
        nodes.push(t2->left);
        nodes.push(t1->right);
        nodes.push(t2->right);
    }

    return true;
}

int main() {
    TreeNode* root1 = nullptr;
    TreeNode* root2 = nullptr;

    cout << "Enter nodes for the first tree (enter -1 for null):\n";
    root1 = userInputTree(root1);

    cout << "Enter nodes for the second tree (enter -1 for null):\n";
    root2 = userInputTree(root2);

    if (isSameTree(root1, root2)) {
        cout << "The trees are identical.\n";
    } else {
        cout << "The trees are not identical.\n";
    }

    return 0;
}

