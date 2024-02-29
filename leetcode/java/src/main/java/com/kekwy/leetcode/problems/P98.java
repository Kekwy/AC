package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P98 {

    class Solution {

        private boolean helper(TreeNode node, Integer upperBound, Integer lowerBound) {
            if (node == null) return true;
            if ((upperBound == null || node.val < upperBound) && (lowerBound == null || node.val > lowerBound)) {
                return helper(node.left, node.val, lowerBound) && helper(node.right, upperBound, node.val);
            }
            return false;
        }

        public boolean isValidBST(TreeNode root) {
            return helper(root, null, null);
        }
    }

}
