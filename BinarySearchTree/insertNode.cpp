#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert (TreeNode* curr, int data) {
    TreeNode* temp = curr;
    while (temp) {
        if (temp->val == data) {
            return NULL;
        }
        if (temp->val > data) {
            if (temp->left == NULL) {
                temp->left = new TreeNode(data);
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = new TreeNode(data);
                break;
            } else {
                temp = temp->right;
            }
        }
    }
    return curr;
}

int main() {
    
    return 0;
}