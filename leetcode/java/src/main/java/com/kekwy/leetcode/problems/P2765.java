package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/23 21:36
 */
public class P2765 {

    class Solution {
        public int alternatingSubarray(int[] nums) {
            int res = -1;
            int len = -1, target = 1;
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] - nums[i - 1] == target) {
                    if (len == -1) len = 2;
                    else len++;
                    target = -target;
                } else {
                    if (len > res) res = len;
                    if (nums[i] - nums[i - 1] == 1) {
                        target = -1;
                        len = 2;
                    } else {
                        target = 1;
                        len = -1;
                    }
                }
            }
            if (len > res) res = len;
            return res;
        }
    }

}
