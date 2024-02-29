package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P700 {

    class Solution {
        public TreeNode searchBST(TreeNode root, int val) {
            if (root == null) return null;
            if (root.val > val) return searchBST(root.left, val);
            else if (root.val < val) return searchBST(root.right, val);
            else return root;
        }
    }

}
