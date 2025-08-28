#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

int ceil (TreeNode* root, int data) {
    int ceil = -1;

    while (root != NULL) {
        if (root->val == data) {
            return data;
        }
        if (data < root->val) {
            ceil = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceil;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);
    int data = 12;
    int result = ceil(root, data);
    cout << "Ceil of " << data << " is " << result << endl; 
    return 0;
}