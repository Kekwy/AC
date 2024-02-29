package com.kekwy.leetcode;

import com.kekwy.leetcode.util.TreeNode;
import org.junit.jupiter.api.Test;

import java.util.*;

public class Problems {


}

class P235 {

    class Solution {
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            if (root == null) return null;
            if (root.val <= Math.max(p.val, q.val) && root.val >= Math.min(p.val, q.val)) { // 以自己为根的情况
                return root;
            }
            TreeNode left = lowestCommonAncestor(root.left, p, q);
            if (left != null) return left;
            return lowestCommonAncestor(root.right, p, q);
        }
    }

}

class P701 {

    class Solution {

        private void helper(TreeNode node, int val) {
            if (val > node.val) {
                if (node.right == null) {
                    node.right = new TreeNode(val);
                } else {
                    helper(node.right, val);
                }
            } else if (val < node.val) {
                if (node.left == null) {
                    node.left = new TreeNode(val);
                } else {
                    helper(node.left, val);
                }
            }
        }

        public TreeNode insertIntoBST(TreeNode root, int val) {
            if (root == null) return new TreeNode(val);
            helper(root, val);
            return root;
        }
    }

}

class P450 {

    class Solution {

        private TreeNode getNext(TreeNode node) {
            TreeNode res = node.right;
            while (res.left != null) {
                res = res.left;
            }
            return res;
        }

        private void swap(TreeNode node1, TreeNode node2) {
            int val = node1.val;
            node1.val = node2.val;
            node2.val = val;
        }

        // 返回值为从当前子树中删除指定节点后，新树的根
        public TreeNode deleteNode(TreeNode root, int key) {
            if (root == null) return null;
            else if (key > root.val) {
                root.right = deleteNode(root.right, key);
            } else if (key < root.val) {
                root.left = deleteNode(root.left, key);
            } else {
                // 叶结点
                if (root.left == null && root.right == null) return null;
                    // 左子树为空
                else if (root.left == null) return root.right;
                    // 右子树为空
                else if (root.right == null) return root.left;
                    // 均不为空
                else {
                    TreeNode next = getNext(root);
                    swap(root, next);
                    root.right = deleteNode(root.right, key);
                }
            }
            return root;
        }
    }

}

class P669 {

    class Solution {
        public TreeNode trimBST(TreeNode root, int low, int high) {
            if (root == null) return null;
            if (root.val < low) return trimBST(root.right, low, high);
            if (root.val > high) return trimBST(root.left, low, high);
            root.left = trimBST(root.left, low, high);
            root.right = trimBST(root.right, low, high);
            return root;
        }
    }

}

class P108 {

    class Solution {

        private TreeNode helper(int[] nums, int begin, int end) {
            if (begin >= end) return null;
            int mid = begin + (end - begin) / 2;
            TreeNode node = new TreeNode(nums[mid]);
            node.left = helper(nums, begin, mid);
            node.right = helper(nums, mid + 1, end);
            return node;
        }

        // 二分查找的查找判定树
        public TreeNode sortedArrayToBST(int[] nums) {
            return helper(nums, 0, nums.length);
        }
    }

}

class P538 {

    class Solution {

        int sum = 0;

        public TreeNode convertBST(TreeNode root) {
            if (root == null) return null;
            convertBST(root.right);
            sum += root.val;
            root.val = sum;
            convertBST(root.left);
            return root;
        }
    }

}

class P2673 {

    class Solution {

        int sum = 0;

        private int helper(int n, int[] cost, int i) {
            if (i > n) return 0;
            int leftSum = helper(n, cost, i * 2);
            int rightSum = helper(n, cost, i * 2 + 1);
            sum += Math.abs(leftSum - rightSum);
            return cost[i - 1] + Math.max(leftSum, rightSum);
        }

        public int minIncrements(int n, int[] cost) {
            helper(n, cost, 1);
            return sum;
        }
    }

}

class P1768 {

    class Solution {
        public String mergeAlternately(String word1, String word2) {
            int i = 0;
            StringBuilder builder = new StringBuilder();
            while (i < word1.length() && i < word2.length()) {
                builder.append(word1.charAt(i));
                builder.append(word2.charAt(i));
                i++;
            }
            while (i < word1.length()) {
                builder.append(word1.charAt(i++));
            }
            while (i < word2.length()) {
                builder.append(word2.charAt(i++));
            }
            return builder.toString();
        }
    }

}

class P155 {

    class MinStack {

        private final Stack<Integer> stack2;

        private final Stack<Integer> stack;

        public MinStack() {
            stack2 = new Stack<>();
            stack = new Stack<>();
        }

        public void push(int val) {
            stack.push(val);
            if (stack2.isEmpty() || stack2.peek() >= val) {
                stack2.push(val);
            }
        }

        public void pop() {
            if (Objects.equals(stack.peek(), stack2.peek())) {
                stack2.pop();
            }
            stack.pop();
        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
            return stack2.peek();
        }
    }

    @Test
    public void test() {
        MinStack minStack = new MinStack();
        MinStack obj = new MinStack();
        obj.push(-2);
        obj.pop();
        int param_3 = obj.top();
        int param_4 = obj.getMin();
    }

}

