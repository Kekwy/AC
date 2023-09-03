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
        if (root->val > max(p->val, q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

#endif //CPP_SOLUTION_H
