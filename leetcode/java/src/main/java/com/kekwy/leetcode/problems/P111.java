package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class P111 {

    class Solution {
        public int minDepth(TreeNode root) {
            Queue<TreeNode> queue = new LinkedList<>();
            if (root != null) {
                queue.offer(root);
            }
            int res = 0;
            while (!queue.isEmpty()) {
                res++;
                int n = queue.size();
                for (int i = 0; i < n; i++) {
                    TreeNode node = queue.poll();
                    if (node.left == null && node.right == null) {
                        queue.clear();
                        break;
                    }
                    if (node.left != null) queue.offer(node.left);
                    if (node.right != null) queue.offer(node.right);
                }
            }
            return res;
        }
    }

}
