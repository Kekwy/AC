package com.kekwy.leetcode.util;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/24 23:58
 */
public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
