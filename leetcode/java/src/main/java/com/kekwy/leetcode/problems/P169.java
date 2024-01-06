package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.Sort;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/majority-element/">169. 多数元素</a>
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/6 11:34
 */
public class P169 {

    /**
     * 哈希统计法
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    class Solution1 {
        public int majorityElement(int[] nums) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int num : nums) {
                Integer count = map.getOrDefault(num, 0);
                count++;
                map.put(num, count);
            }
            int target = nums.length / 2;
            int res = 0;
            for (Integer num : map.keySet()) {
                if (map.get(num) > target) {
                    res = num;
                    break;
                }
            }
            return res;
        }
    }

    class Solution2 {
        public int majorityElement(int[] nums) {
            int[] ints = Arrays.stream(nums).sorted().toArray();
            return ints[ints.length / 2];
        }
    }

    /**
     * 摩尔投票法
     * 空间复杂度：O(n)
     * 时间复杂度：O(1)
     */
    class Solution3 {
        public int majorityElement(int[] nums) {
            int x = 0, votes = 0;
            for (int num : nums) {
                if (votes == 0) x = num;
                votes += num == x ? 1 : -1;
            }
            return x;
        }
    }

    @Test
    public void testSolution() {
        System.out.println(new Solution3().majorityElement(new int[]{1, 2, 3, 2, 2, 2, 5, 4, 2}));
    }

}
