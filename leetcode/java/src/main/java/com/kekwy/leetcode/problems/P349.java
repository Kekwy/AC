package com.kekwy.leetcode.problems;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/19 8:02
 */
public class P349 {
    class Solution {
        public int[] intersection(int[] nums1, int[] nums2) {
            Set<Integer> set1 = new HashSet<>();
            for (int i : nums1) set1.add(i);
            Set<Integer> set2 = new HashSet<>();
            for (int i : nums2) {
                if (set1.contains(i)) {
                    set2.add(i);
                }
            }
            int[] res = new int[set2.size()];
            int i = 0;
            for (Integer num : set2) {
                res[i++] = num;
            }
            return res;
        }
    }
}
