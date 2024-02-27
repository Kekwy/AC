package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P112 {

    class Solution {

        public boolean hasPathSum(TreeNode root, int targetSum) {
            if (root == null) return false;
            targetSum -= root.val;
            if (targetSum == 0 && root.left == null && root.right == null) {
                return true;
            }
            return hasPathSum(root.left, targetSum) || hasPathSum(root.right, targetSum);
        }
    }

}
