//https://leetcode.com/problems/invert-binary-tree/description/
#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to swap the left and right child nodes of a tree node
void swapChildren(TreeNode* curr) {
    if (!curr) {
        return;  // Handle empty node case
    }
    swapChildren(curr->left);
    swapChildren(curr->right);

    TreeNode* temp = curr->left;
    curr->left = curr->right;
    curr->right = temp;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    swapChildren(root);

    std::cout << "Inverted Tree: ";
    std::cout << root->val << " ";
    std::cout << root->left->val << " ";
    std::cout << root->right->val << " ";
    std::cout << root->left->left->val << " ";
    std::cout << root->left->right->val << " ";
    std::cout << root->right->left->val << " ";
    std::cout << root->right->right->val << " ";

    std::cout << std::endl;

    return 0;
}
