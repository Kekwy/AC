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

    bool rootSelected(TreeNode *A, TreeNode *B) {
        if (B == nullptr) return true;
        else if (A == nullptr) return false;
        if (A->val == B->val) {
            return rootSelected(A->left, B->left) && rootSelected(A->right, B->right);
        }
        return false;
    }

    bool rootToBeSelected(TreeNode *A, TreeNode *B) {
        if (B == nullptr) return true;
        else if (A == nullptr) return false;
        return rootToBeSelected(A->left, B) || rootToBeSelected(A->right, B) || rootSelected(A, B);
    }

public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr) return false;
        return rootToBeSelected(A, B);
    }
};

#endif //CPP_SOLUTION_H
