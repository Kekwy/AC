package com.kekwy.leetcode.problems;

import java.util.List;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/25 20:15
 */
public class P2859 {

    class Solution {

        private int getSetBits(int i) {
            int res = 0;
            while (i > 0) {
                res += i % 2;
                i /= 2;
            }
            return res;
        }

        public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
            int res = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (getSetBits(i) == k) res += nums.get(i);
            }
            return res;
        }
    }

}
