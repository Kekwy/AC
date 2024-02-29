package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class P530 {

    /**
     * tips：二叉搜索树的中序遍历序列为升序数组
     */
    class Solution {

        private void helper(TreeNode node, List<Integer> traverseRes) {
            if (node == null) return;
            helper(node.left, traverseRes);
            traverseRes.add(node.val);
            helper(node.right, traverseRes);
        }

        public int getMinimumDifference(TreeNode root) {
            List<Integer> traverseRes = new ArrayList<>();
            helper(root, traverseRes);
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < traverseRes.size() - 1; i++) {
                int diff = traverseRes.get(i + 1) - traverseRes.get(i);
                if (diff < min) {
                    min = diff;
                }
            }
            return min;
        }
    }

}
