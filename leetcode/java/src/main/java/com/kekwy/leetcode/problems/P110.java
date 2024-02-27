package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P110 {

    class Solution {

        private int helper(TreeNode node) {
            if (node == null) return 0;
            int rightHeight = helper(node.right);
            int leftHeight = helper(node.left);
            if (rightHeight != -1
                && leftHeight != -1
                && Math.abs(rightHeight - leftHeight) <= 1) {
                return Math.max(rightHeight, leftHeight) + 1;
            } else {
                return -1;
            }
        }

        public boolean isBalanced(TreeNode root) {
            return helper(root) != -1;
        }
    }

}
