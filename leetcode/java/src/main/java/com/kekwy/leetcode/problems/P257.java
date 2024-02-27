package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class P257 {

    class Solution {

        private final List<String> res = new ArrayList<>();

        private void helper(TreeNode node, String path) {
            path += node.val;
            if (node.right == null && node.left == null) {
                res.add(path);
            } else {
                if (node.right != null) {
                    helper(node.right, path + "->");
                }
                if (node.left != null) {
                    helper(node.left, path + "->");
                }
            }
        }

        public List<String> binaryTreePaths(TreeNode root) {
            if (root != null) {
                helper(root, "");
            }
            return res;
        }
    }

}
