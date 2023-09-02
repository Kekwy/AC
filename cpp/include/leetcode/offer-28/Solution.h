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

    void visit(TreeNode *root) {
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == nullptr) return nullptr;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        visit(root);
        return root;
    }
};

#endif //CPP_SOLUTION_H
