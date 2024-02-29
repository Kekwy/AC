package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P106 {

    class Solution {

        int i;

        private TreeNode helper(int[] inorder, int[] postorder, int begin, int end) {
            if (begin >= end) return null;
            for (int j = begin; j < end; j++) {
                if (inorder[j] == postorder[i]) {
                    i--;
                    TreeNode node = new TreeNode(inorder[j]);
                    node.left = helper(inorder, postorder, begin, j);
                    node.right = helper(inorder, postorder, j + 1, end);
                    return node;
                }
            }
            return null;
        }

        public TreeNode buildTree(int[] inorder, int[] postorder) {
            i = postorder.length - 1;
            return helper(inorder, postorder, 0, inorder.length);
        }
    }

}
