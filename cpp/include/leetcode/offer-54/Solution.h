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

    int n;

    int res = -1;

    bool isFound = false;

    void visit(TreeNode *node) {
        if (isFound) return;
        n--;
        if (n == 0) {
            res = node->val;
            isFound = true;
        }
    }

    void travel(TreeNode *node) {
        if (node == nullptr) return;
        travel(node->right);
        visit(node);
        travel(node->left);
    }

public:
    int kthLargest(TreeNode* root, int k) {
        n = k;
        travel(root);
        return res;
    }
};

#endif //CPP_SOLUTION_H
