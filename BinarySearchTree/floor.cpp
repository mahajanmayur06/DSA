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

int floor (TreeNode* root, int data) {
    int res = -1;

    while (root != NULL) {
        if (root->val == data) {
            return data;
        }
        if (data > root->val) {
            res = root->val;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);
    int data = 6;
    int result = floor(root, data);
    cout << "Floor of " << data << " is " << result << endl;
    return 0;
}