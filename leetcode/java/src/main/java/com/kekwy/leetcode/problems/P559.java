package com.kekwy.leetcode.problems;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class P559 {

    class Node {
        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }

    class Solution {
        public int maxDepth(Node root) {
            Queue<Node> queue = new LinkedList<>();
            if (root != null) queue.offer(root);
            int layer = 0;
            while (!queue.isEmpty()) {
                layer++;
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    Node node = queue.poll();
                    if (node != null && node.children != null) {
                        for (Node child : node.children) {
                            queue.offer(child);
                        }
                    }
                }
            }
            return layer;
        }
    }

}
