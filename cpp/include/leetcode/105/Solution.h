//
// Created by Kekwy on 2023/8/5.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

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

// class Solution {

//     TreeNode *helper(int &index, vector<int> &preorder, int begin, int end, vector<int> &inorder) {
//         if (begin >= end) return nullptr;
//         int temp = 0;
//         for (int i = begin; i < end; ++i) {
//             if (inorder[i] == preorder[index]) {
//                 temp = i;
//                 break;
//             }
//         }
//         index++;
//         TreeNode *left = helper(index, preorder, begin, temp, inorder);
//         TreeNode *right = helper(index, preorder, temp + 1, end, inorder);
//         return new TreeNode(preorder[index], left, right);
//     }


// public:
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//         int index = 0;
//         return helper(index, preorder, 0, (int) inorder.size(), inorder);
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
