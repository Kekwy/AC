//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <stack>
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
    bool isSymmetricEqual(TreeNode *a, TreeNode *b) {
        if (a == nullptr && b == nullptr) return true;
        else if (a == nullptr || b == nullptr || a->val != b->val) return false;
        return isSymmetricEqual(a->left, b->right) && isSymmetricEqual(a->right, b->left);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return isSymmetricEqual(root->left, root->right);
    }
};

#endif //CPP_SOLUTION_H
