package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;

public class P113 {

    class Solution {

        private List<Integer> path = new LinkedList<>();

        private List<List<Integer>> res = new LinkedList<>();

        private void helper(TreeNode node, int targetSum) {
            if (node == null) return;
            path.add(node.val);
            targetSum -= node.val;
            if (targetSum == 0 && node.left == null && node.right == null) {
                res.add(List.copyOf(path));
            }
            helper(node.left, targetSum);
            helper(node.right, targetSum);
            path.remove(path.size() - 1);
        }

        public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
            if (root != null) helper(root, targetSum);
            return res;
        }
    }

}
