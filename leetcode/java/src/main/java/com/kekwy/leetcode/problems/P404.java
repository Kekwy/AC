package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P404 {

    class Solution {

        private int helper(TreeNode node, boolean isLeft) {
            if (node.left == null && node.right == null) {
                if (isLeft) return node.val;
                else return 0;
            }
            int sum = 0;
            if (node.left != null) sum += helper(node.left, true);
            if (node.right != null) sum += helper(node.right, false);
            return sum;
        }

        public int sumOfLeftLeaves(TreeNode root) {
            if (root != null) {
                return helper(root, false);
            }
            return 0;
        }
    }

}
