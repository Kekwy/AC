package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.Stack;

public class P100 {

    class Solution {
        public boolean isSameTree(TreeNode p, TreeNode q) {
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
    }

}
