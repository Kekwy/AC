package com.kekwy.leetcode.p1;

import java.util.HashMap;
import java.util.Map;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/9/21 11:48
 */
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = null;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int other = target - num;
            if (map.containsKey(other)) {
                res = new int[]{map.get(other), i};
                break;
            }
            map.put(num, i);
        }
        return res;
    }
}