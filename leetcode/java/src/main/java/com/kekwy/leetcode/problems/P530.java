package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P530 {

    class Solution {

        int min = Integer.MAX_VALUE;

        private void helper(TreeNode node) {
            if (min == 0) return;
            if (node.left != null) {
                int diff = node.val - node.left.val;
                if (diff < min) {
                    min = diff;
                }
                helper(node.left);
            }
            if (node.right != null) {
                int diff = node.right.val - node.val;
                if (diff < min) {
                    min = diff;
                }
                helper(node.right);
            }
        }

        public int getMinimumDifference(TreeNode root) {
            helper(root);
            return min;
        }
    }

}
