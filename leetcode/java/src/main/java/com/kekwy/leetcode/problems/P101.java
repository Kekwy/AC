package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.*;

public class P101 {

    class Solution {
        public boolean isSymmetric(TreeNode root) {
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            while (!queue.isEmpty()) {
                List<Integer> valueList = new ArrayList<>();
                int n = queue.size();
                for (int i = 0; i < n; i++) {
                    TreeNode node = queue.poll();
                    if (node.left != null) {
                        valueList.add(node.left.val);
                        queue.offer(node.left);
                    } else {
                        valueList.add(null);
                    }
                    if (node.right != null) {
                        valueList.add(node.right.val);
                        queue.offer(node.right);
                    } else {
                        valueList.add(null);
                    }
                }
                int lp = 0, rp = valueList.size() - 1;
                while (lp < rp) {
                    if (!Objects.equals(valueList.get(lp), valueList.get(rp))) {
                        return false;
                    }
                    lp++;
                    rp--;
                }
            }
            return true;
        }
    }

}
