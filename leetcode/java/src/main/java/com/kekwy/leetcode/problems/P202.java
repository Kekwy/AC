package com.kekwy.leetcode.problems;

import java.util.HashSet;
import java.util.Set;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/19 11:13
 */
public class P202 {
    class Solution {

        Set<Integer> set = new HashSet<>();

        public boolean isHappy(int n) {
            if (n == 1) return true; // 1 是快乐数，返回 true
            // 若在 n 在递归的过程中已经出现，
            // 说明出现循环，则该数不是快乐数
            if (set.contains(n)) return false;
            set.add(n); // 记录当前 n
            // 求各位数的平方和
            int digitSum = 0;
            for (int i = n; i > 0; i /= 10) {
                int digit = i % 10;
                digitSum += digit * digit;
            }
            return isHappy(digitSum);
        }
    }
}
