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
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        bool flag = true;
        auto stack1 = stack<TreeNode *>();
        auto stack2 = stack<TreeNode *>();
        int layer = 0;
        auto res = vector<vector<int>>();
        if (root != nullptr) stack1.push(root);
        while (!stack1.empty() || !stack2.empty()) {
            res.push_back(vector<int>());
            if (flag) {
                while (!stack1.empty()) {
                    TreeNode *node = stack1.top();
                    stack1.pop();
                    res[layer].push_back(node->val);
                    if (node->left != nullptr) stack2.push(node->left);
                    if (node->right != nullptr) stack2.push(node->right);
                }
                flag = false;
            } else {
                while (!stack2.empty()) {
                    TreeNode *node = stack2.top();
                    stack2.pop();
                    res[layer].push_back(node->val);
                    if (node->right != nullptr) stack1.push(node->right);
                    if (node->left != nullptr) stack1.push(node->left);
                }
                flag = true;
            }
            layer++;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H
