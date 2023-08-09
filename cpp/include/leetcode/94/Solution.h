//
// Created by Kekwy on 2023/8/9.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <stack>

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

    void helper(TreeNode *root, vector<int> &res) {
        if (root->left != nullptr) helper(root->left, res);
        res.push_back(root->val);
        if (root->right != nullptr) helper(root->right, res);
    }

public:
// TODO: 用栈实现非递归的中序遍历


// 以下代码的错误为，当左子树结束遍历后，再次处理根结点时，无法判断根结点的左子树是否已经完成遍历。

//    vector<int> inorderTraversal(TreeNode *root) {
//        vector<int> res;
//        stack<TreeNode *> myStack;
//        myStack.push(root);
//        while (!myStack.empty()) {
//            TreeNode *top = myStack.top();
//            if (top->left != nullptr) {     // 遍历左子树
//                myStack.push(top->left);
//                continue;
//            }
//            myStack.pop();
//            res.push_back(top->val);        // 遍历根结点
//            if (top->right != nullptr) {    // 遍历右子树
//                myStack.push(top->right);
//                continue;
//            }
//        }
//        return res;
//    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root != nullptr) helper(root, res);
        return res;
    }

};

#endif //CPP_SOLUTION_H
