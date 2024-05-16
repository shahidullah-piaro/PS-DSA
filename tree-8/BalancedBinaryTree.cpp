//https://leetcode.com/problems/balanced-binary-tree/description/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to create a new tree node
TreeNode* newNode(int data) {
    return new TreeNode(data);
}

int Height(TreeNode* root) {
        // Base case...
		if (root == NULL)  return 0;
        // Height of left subtree...
		int leftHeight = Height(root->left);
        // Height of height subtree...
		int rightHight = Height(root->right);
        // In case of left subtree or right subtree unbalanced or their heights differ by more than ‘1’, return -1...
		if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)  return -1;
        // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
		return max(leftHeight, rightHight) + 1;
    }

// Function to check if a binary tree is balanced (efficient approach)
bool isBalanced(TreeNode* root) {
        // If the tree is empty, we can say it’s balanced...
        if (root == NULL)  return true;
        // Height Function will return -1, when it’s an unbalanced tree...
		if (Height(root) == -1)  return false;
		return true;
	}
// Function to get user input for creating a binary tree (example)
TreeNode* createTree() {
    int data;
    cout << "Enter data (enter -1 for null): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    TreeNode* root = newNode(data);
    root->left = createTree();
    root->right = createTree();

    return root;
}

int main() {
    TreeNode* root = createTree();

    if (isBalanced(root) == -1) {
        cout << "The tree is not balanced." << endl;
    } else {
        cout << "The tree is balanced." << endl;
    }

    return 0;
}

