//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

#include <iostream>

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
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr) return nullptr;
        else if (right == nullptr) return left;
        else if (left == nullptr) return right; 
        else return root;
    }
};

#endif //CPP_SOLUTION_H
