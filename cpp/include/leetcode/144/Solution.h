//
// Created by Kekwy on 2023/8/5.
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

    void helper(TreeNode *root, vector<int> &res) {
        res.push_back(root->val); // 遍历当前结点
        if (root->left != nullptr) helper(root->left, res); // 遍历左子树
        if (root->right != nullptr) helper(root->right, res); // 遍历右子树
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root != nullptr) {
            helper(root, res);
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H
