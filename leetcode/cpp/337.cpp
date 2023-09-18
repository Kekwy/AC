/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=21913
 *
 * [337] 打家劫舍 III
 */
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

    unordered_map<TreeNode *, int> dp;

    void travel(TreeNode *node) {
        if (node == nullptr) return;
        travel(node->left);
        travel(node->right);
        int sum1 = dp[node->left] + dp[node->right];
        int sum2 = node->val
            + (node->left == nullptr ? 0 : (dp[node->left->left] + dp[node->left->right]))
            + (node->right == nullptr ? 0 : (dp[node->right->left] + dp[node->right->right]));
        dp[node] = max(sum1, sum2);
    }

public:
    int rob(TreeNode *root) {
        dp[nullptr] = 0;
        travel(root);
        return dp[root];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */

