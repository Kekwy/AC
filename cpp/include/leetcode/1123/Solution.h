//
// Created by Kekwy on 2023/9/6.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

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

    TreeNode *travel(TreeNode *root, int &depth) {
        if (root == nullptr) {
            depth = 0;
            return nullptr;
        }
        int lDepth = 0, rDepth = 0;
        TreeNode *lp = travel(root->left, lDepth);
        TreeNode *rp = travel(root->right, rDepth);
        if (lDepth > rDepth) {
            depth = lDepth + 1;
            return lp;
        }
        else if (lDepth < rDepth) {
            depth = rDepth + 1;
            return rp;
        }
        else {
            depth = lDepth + 1;
            return root;
        }
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        int depth = 0;
        return travel(root, depth);
    }
};

#endif //CPP_SOLUTION_H
