//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    
    int balancedHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = balancedHeight(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = balancedHeight(root->right);
        if (rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }

public:

    bool isBalanced(TreeNode* root) {
        return balancedHeight(root) != -1;
    }
    
};

#endif //CPP_SOLUTION_H
