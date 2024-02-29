package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

public class P654 {

    class Solution {

        private TreeNode helper(int[] nums, int begin, int end) {
            if (begin >= end) return null;
            int index = begin;
            int max = nums[begin];
            for (int i = begin + 1; i < end; i++) {
                if (nums[i] > max) {
                    index = i;
                    max = nums[i];
                }
            }
            TreeNode node = new TreeNode(max);
            node.left = helper(nums, begin, index);
            node.right = helper(nums, index + 1, end);
            return node;
        }

        public TreeNode constructMaximumBinaryTree(int[] nums) {
            return helper(nums, 0, nums.length);
        }
    }

}
