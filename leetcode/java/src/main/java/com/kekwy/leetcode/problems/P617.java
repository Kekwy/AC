package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P617 {

    class Solution {

        public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
            if (root1 == null && root2 == null) {
                return null;
            } else if (root1 == null) {
                return root2;
            } else if (root2 == null) {
                return root1;
            } else {
                TreeNode node = new TreeNode(root1.val + root2.val);
                node.left = mergeTrees(root1.left, root2.left);
                node.right = mergeTrees(root1.right, root2.right);
                return node;
            }
        }
    }

}
