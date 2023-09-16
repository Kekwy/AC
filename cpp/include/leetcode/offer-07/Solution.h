//
// Created by Kekwy on 2023/9/16.
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    vector<int> *preorder;
    vector<int> *inorder;
    int i = 0;

    void partition(TreeNode *&node, int begin, int end) {
        if (begin >= end) return;
        int val = (*preorder)[i];
        int j = begin;
        for (; j < end && (*inorder)[j] != val; j++);
        if (j == end) return;
        i++;
        node = new TreeNode(val);
        partition(node->left, begin, j);
        partition(node->right, j + 1, end);
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->preorder = &preorder;
        this->inorder = &inorder;
        TreeNode *root = nullptr;
        partition(root, i, inorder.size());
        return root;
    }
};

#endif //CPP_SOLUTION_H
