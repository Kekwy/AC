package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P236 {

    class Solution {

        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            if (root == p || root == q || root == null) return root;
            TreeNode left = lowestCommonAncestor(root.left, p, q);
            TreeNode right = lowestCommonAncestor(root.right, p, q);
            if (left != null && right != null) return root;
            else if (left != null) return left;
            else return right;
        }
    }

}
