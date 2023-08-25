//
// Created by Kekwy on 2023/8/25.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    int helper(TreeNode *root, int max) {
        if (root == nullptr) return 0;
        int count = 0;
        if (root->val >= max) {
            max = root->val;
            count = 1;
        }
        return count + helper(root->left, max) + helper(root->right, max);
    }

public:
    int goodNodes(TreeNode* root) {
        return 1 + helper(root->left, root->val) + helper(root->right, root->val);
    }
};

#endif //CPP_SOLUTION_H
