package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P226 {

    class Solution {

        private void helper(TreeNode node) {
            if (node == null) return;
            helper(node.left);
            helper(node.right);
            TreeNode left = node.left;
            node.left = node.right;
            node.right = left;
        }

        public TreeNode invertTree(TreeNode root) {
            helper(root);
            return root;
        }
    }

}
