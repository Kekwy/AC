package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class P572 {
    class Solution {

        private boolean isSameTree(TreeNode p, TreeNode q) {
            Stack<TreeNode> stack = new Stack<>();
            stack.push(p);
            stack.push(q);
            while(!stack.isEmpty()) {
                TreeNode node1 = stack.pop();
                TreeNode node2 = stack.pop();
                if (node1 == null && node2 == null) {
                    continue;
                } else if (node1 == null || node2 == null) {
                    return false;
                } else if (node1.val != node2.val) {
                    return false;
                } else {
                    stack.push(node1.left);
                    stack.push(node2.left);
                    stack.push(node1.right);
                    stack.push(node2.right);
                }
            }
            return true;
        }

        public boolean isSubtree(TreeNode root, TreeNode subRoot) {
            Stack<TreeNode> stack = new Stack<>();
            if (root != null) {
                stack.push(root);
            }
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                if (isSameTree(node, subRoot)) return true;
                if (node.left != null) stack.push(node.left);
                if (node.right != null) stack.push(node.right);
            }
            return false;
        }
    }
}
