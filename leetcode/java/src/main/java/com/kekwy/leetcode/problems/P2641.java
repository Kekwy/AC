package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/2/7 7:22
 */
public class P2641 {

    class Solution {
        public TreeNode replaceValueInTree(TreeNode root) {
            List<TreeNode> nodes = new ArrayList<>();
            root.val = 0;
            nodes.add(root);
            while (!nodes.isEmpty()) {
                int childSum = 0;
                List<TreeNode> childList = new ArrayList<>();
                for (TreeNode node : nodes) {
                    if (node.left != null) {
                        childSum += node.left.val;
                        childList.add(node.left);
                    }
                    if (node.right != null) {
                        childSum += node.right.val;
                        childList.add(node.right);
                    }
                }
                for (TreeNode node : nodes) {
                    if (node.left != null && node.right != null) {
                        int sum = node.left.val + node.right.val;
                        node.left.val = childSum - sum;
                        node.right.val = childSum - sum;
                    } else if (node.right != null) {
                        node.right.val = childSum - node.right.val;
                    } else if (node.left != null) {
                        node.left.val = childSum - node.left.val;
                    }
                }
                nodes = childList;
            }
            return root;
        }
    }

}
