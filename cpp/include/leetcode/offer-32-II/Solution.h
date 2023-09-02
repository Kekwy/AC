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
    vector<vector<int>> levelOrder(TreeNode *root) {
        auto que = queue<pair<TreeNode *, int>>();
        auto res = vector<vector<int>>();
        if (root != nullptr) que.push(make_pair(root, 0));
        while (!que.empty()) {
            TreeNode *node = que.front().first;
            int layer = que.front().second;
            que.pop();
            if (layer >= res.size()) res.push_back(vector<int>());
            res[layer].push_back(node->val);
            if (node->left != nullptr) que.push(make_pair(node->left, layer + 1));
            if (node->right != nullptr) que.push(make_pair(node->right, layer + 1));
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H
