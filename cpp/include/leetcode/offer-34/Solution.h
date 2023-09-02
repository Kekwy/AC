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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    void recur(TreeNode *node, int target, vector<vector<int>> &res, vector<int> &path) {
        if (node != nullptr) {
            path.push_back(node->val);
            target -= node->val;
            if (node->left == nullptr && node->right == nullptr && target == 0) {
                res.push_back(path);
            } else {
                recur(node->left, target, res, path);
                recur(node->right, target, res, path);
            }
            path.pop_back();
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        auto res = vector<vector<int>>();
        auto path = vector<int>();
        recur(root, target, res, path);
        return res;
    }
};

#endif //CPP_SOLUTION_H
