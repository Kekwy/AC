/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30103
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */


 // @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    TreeNode *partition(vector<int> &preorder, vector<int> &inorder, int begin, int end, int &i) {
        if (begin >= end) {
            return nullptr;
        }
        int val = preorder[i];
        int j = begin;
        for (; j < end && inorder[j] != preorder[i]; j++);
        if (j == end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = partition(preorder, inorder, begin, j, i);
        root->right = partition(preorder, inorder, j + 1, end, i);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int i = 0;
        return partition(preorder, inorder, i, inorder.size(), i);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

