package com.kekwy.leetcode.problems;

import java.util.HashMap;
import java.util.Map;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/19 15:43
 */
public class P454 {
    class Solution {
        public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int i : nums1) {
                for (int j : nums2) {
                    int sum = i + j;
                    map.put(sum, map.getOrDefault(sum, 0) + 1);
                }
            }
            int res = 0;
            for (int i : nums3) {
                for (int j : nums4) {
                    int sum = i + j;
                    res += map.getOrDefault(-sum, 0);
                }
            }
            return res;
        }
    }
}
