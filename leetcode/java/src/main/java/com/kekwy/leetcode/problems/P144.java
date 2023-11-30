package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/24 23:58
 */
public class P144 {
    class Solution {
        public List<Integer> preorderTraversal(TreeNode root) {
            List<Integer> res = new LinkedList<>();
            Stack<TreeNode> stack = new Stack<>();
            if (root != null) stack.push(root);
            while (!stack.empty()) {
                TreeNode node = stack.pop();
                if (node != null) {
                    if (node.right != null) stack.push(node.right); // 右
                    if (node.left != null) stack.push(node.left);   // 左
                    stack.push(node);       // 中
                    stack.push(null);
                } else {
                    node = stack.pop();
                    res.add(node.val);
                }
            }
            return res;
        }
    }
}
