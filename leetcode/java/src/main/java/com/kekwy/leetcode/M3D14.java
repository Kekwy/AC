package com.kekwy.leetcode;


import com.kekwy.leetcode.util.TreeNode;

import java.util.*;

class P2789 {

    class Solution {
        public long maxArrayValue(int[] nums) {
            int i = nums.length - 2;
            long res = nums[nums.length - 1];
            while (i >= 0) {
                if (nums[i] <= res) {
                    res += nums[i];
                } else {
                    res = nums[i];
                }
                i--;
            }
            return res;
        }
    }

}

class P117 {

    class Node {
        public int val;
        public Node left;
        public Node right;
        public Node next;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, Node _left, Node _right, Node _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    }

    class Solution {
        public Node connect(Node root) {
            Queue<Node> queue = new LinkedList<>();
            if (root != null) {
                queue.offer(root);
            }
            while (!queue.isEmpty()) {
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    Node node = queue.poll();
                    if (i == size - 1) {
                        node.next = null;
                    } else {
                        node.next = queue.peek();
                    }
                    if (node.left != null) queue.offer(node.left);
                    if (node.right != null) queue.offer(node.right);
                }
            }
            return root;
        }
    }
}

class P114 {
    class Solution {
        public void flatten(TreeNode root) {
            Stack<TreeNode> stack = new Stack<>();
            TreeNode prev = new TreeNode();
            if (root != null) stack.push(root);
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                if (node == null) continue;
                stack.push(node.right);
                stack.push(node.left);
                node.right = null;
                node.left = null;
                prev.right = node;
                prev = node;
            }
        }
    }
}

class P129 {
    class Solution {

        private int helper(TreeNode node, int sum) {
            int curSum = sum * 10 + node.val;
            if (node.left == null && node.right == null) return curSum;
            int res = 0;
            if (node.left != null) {
                res += helper(node.left, curSum);
            }
            if (node.right != null) {
                res += helper(node.right, curSum);
            }
            return res;
        }

        public int sumNumbers(TreeNode root) {
            if (root == null) return 0;
            return helper(root, 0);
        }
    }
}

class P124 {
    class Solution {

        Integer res = null;

        private int helper(TreeNode root) {
            if (root == null) return 0;
            int left = helper(root.left);
            int right = helper(root.right);
            if (left < 0) left = 0;
            if (right < 0) right = 0;
            if (res == null || left + root.val + right > res) {
                res = left + root.val + right;
            }
            return Math.max(left, right) + root.val;
        }

        public int maxPathSum(TreeNode root) {
            helper(root);
            return res;
        }

    }
}

class P199 {

    class Solution {
        public List<Integer> rightSideView(TreeNode root) {
            Queue<TreeNode> queue = new LinkedList<>();
            List<Integer> res = new LinkedList<>();
            if (root != null) queue.offer(root);
            while (!queue.isEmpty()) {
                int size = queue.size();
                int rightVal = 0;
                for (int i = 0; i < size; i++) {
                    TreeNode node = queue.poll();
                    rightVal = node.val;
                    if (node.left != null) queue.offer(node.left);
                    if (node.right != null) queue.offer(node.right);
                }
                res.add(rightVal);
            }
            return res;
        }
    }

}

class P103 {

    class Solution {
        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
            Deque<TreeNode> deque = new LinkedList<>();
            List<List<Integer>> res = new LinkedList<>();
            if (root != null) deque.offerLast(root);
            while (!deque.isEmpty()) {
                List<Integer> list = new LinkedList<>();
                int size = deque.size();
                for (int i = 0; i < size; i++) {
                    TreeNode node = deque.pollFirst();
                    list.add(node.val);
                    if (node.left != null) deque.offerLast(node.left);
                    if (node.right != null) deque.offerLast(node.right);
                }
                if (!list.isEmpty()) res.add(List.copyOf(list));
                list.clear();
                size = deque.size();
                for (int i = 0; i < size; i++) {
                    TreeNode node = deque.pollLast();
                    list.add(node.val);
                    if (node.right != null) deque.offerFirst(node.right);
                    if (node.left != null) deque.offerFirst(node.left);
                }
                if (!list.isEmpty()) res.add(List.copyOf(list));
            }
            return res;
        }
    }

}

class P230 {
    class Solution {

        private void helper(TreeNode node, List<Integer> traverseRes) {
            if (node == null) return;
            helper(node.left, traverseRes);
            traverseRes.add(node.val);
            helper(node.right, traverseRes);
        }

        public int kthSmallest(TreeNode root, int k) {
            List<Integer> traverseRes = new LinkedList<>();
            helper(root, traverseRes);
            return traverseRes.get(k - 1);
        }
    }
}

class P200 {

    class Solution {

        private void helper(char[][] grid, int i, int j, boolean[][] visited) {
            visited[i][j] = true;
            if (i - 1 >= 0 && grid[i - 1][j] == '1' && !visited[i - 1][j]) {
                helper(grid, i - 1, j, visited);
            }
            if (i + 1 < grid.length && grid[i + 1][j] == '1' && !visited[i + 1][j]) {
                helper(grid, i + 1, j, visited);
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]) {
                helper(grid, i, j - 1, visited);
            }
            if (j + 1 < grid[0].length && grid[i][j + 1] == '1' && !visited[i][j + 1]) {
                helper(grid, i, j + 1, visited);
            }
        }

        public int numIslands(char[][] grid) {
            boolean[][] visited = new boolean[grid.length][grid[0].length];
            int res = 0;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    if (grid[i][j] == '1' && !visited[i][j]) {
                        res++;
                        helper(grid, i, j, visited);
                    }
                }
            }
            return res;
        }
    }

}