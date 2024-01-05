package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/1 22:39
 */
public class P88 {
    class Solution {
        public void merge(int[] nums1, int m, int[] nums2, int n) {
            int[] res = new int[m + n];
            int p = 0;
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    res[p++] = nums1[i++];
                } else {
                    res[p++] = nums2[j++];
                }
            }
            for (; i < m; i++) res[p++] = nums1[i];
            for (; j < n; j++) res[p++] = nums2[j];
            if (m + n >= 0) System.arraycopy(res, 0, nums1, 0, m + n);
        }
    }
}
