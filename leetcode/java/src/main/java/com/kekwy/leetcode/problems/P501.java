package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class P501 {

    class Solution {

        public int[] findMode(TreeNode root) {
            List<Integer> res = new LinkedList<>();
            TreeNode prev = null;
            Stack<TreeNode> stack = new Stack<>();
            int maxCount = 0;
            int curCount = 0;
            if (root != null) stack.push(root);
            while (!stack.isEmpty()) {
                TreeNode node = stack.peek();
                if (node != null) {
                    stack.push(null);
                    if (node.left != null) {
                        stack.push(node.left);
                    }
                } else {
                    stack.pop();
                    node = stack.pop();
                    if (prev != null && node.val != prev.val) {
//                        if (curCount > maxCount) {
//                            maxCount = curCount;
//                            res.clear();
//                            res.add(node.val);
//                        } else if (curCount == maxCount) {
//                            res.add(prev.val);
//                        }
                        curCount = 1;
                    } else {
                        curCount++;
                    }
                    if (curCount > maxCount) {
                        maxCount = curCount;
                        res.clear();
                        res.add(node.val);
                    } else if (curCount == maxCount) {
//                        res.add(prev.val);
                        res.add(node.val);
                    }
                    prev = node;
                    if (node.right != null) {
                        stack.push(node.right);
                    }
                }
            }
            return res.stream().mapToInt(Integer::intValue).toArray();
        }
    }

}
