package com.kekwy.leetcode.problems;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/19 11:24
 */
public class P1 {
    class Solution {
        public int[] twoSum(int[] nums, int target) {
            int[] res = new int[2];
            // 注意要返回的是下标
//            Set<Integer> set = new HashSet<>();
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int other = target - nums[i];
                if (map.containsKey(other)) {
                    res[0] = i;
                    res[1] = map.get(other);
                    break;
                }
                map.put(nums[i], i);
            }
            return res;
        }
    }
}
