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
public:
    vector<int> levelOrder(TreeNode *root) {
        auto que = queue<TreeNode *>();
        auto res = vector<int>();
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            res.push_back(node->val);
            if (node->left != nullptr) que.push(node->left);
            if (node->right != nullptr) que.push(node->right);
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H
