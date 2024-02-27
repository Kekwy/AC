package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class P222 {

    class Solution {
        public int countNodes(TreeNode root) {
            Queue<TreeNode> queue = new LinkedList<>();
            if (root != null) queue.offer(root);
            else return 0;
            int layer = 0;
            while (!queue.isEmpty()) {
                int size = queue.size();
                TreeNode node1 = queue.peek();
                if (node1 != null && node1.left == null && node1.right == null) {
                    return (int) (Math.pow(2, layer) - 1 + size);
                }
                for (int i = 0; i < size; i++) {
                    TreeNode node = queue.poll();
                    if (node != null) {
                        if (node.left != null) {
                            queue.offer(node.left);
                        }
//                        else if (node.right != null) { bugfix

                        if (node.right != null) {
                            queue.offer(node.right);
                        }
                    }
                    layer++;
                }
            }
            return -1;
        }
    }
}
