package com.kekwy.leetcode.problems;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class P459 {

    /**
     * 1. 两个 s 拼起来，在中间形成一个新的 s，即可说明 s 由重复的子串构成，而不必求出具体的子串。
     * 2. 直接使用 KMP 算法中对 next 数组的原理，找出组成 s 的最小重复单元。
     * 前缀表里，统计了各个位置为终点字符串的最长相同前后缀的长度。
     */
    class Solution {

        private int[] getNextArray(String pattern) {
            int[] res = new int[pattern.length()];
            int p = 1, q = 0;
            res[0] = q;
            while (p < pattern.length()) {
                while(q > 0 && pattern.charAt(p) != pattern.charAt(q)) {
                    q = res[q - 1];
                }
                if (pattern.charAt(p) == pattern.charAt(q)) q++;
                res[p++] = q;
            }
            return res;
        }

        public boolean repeatedSubstringPattern(String s) {
            int[] next = getNextArray(s);
            int len = next[s.length() - 1];
            return len != 0 && s.length() % (s.length() - len) == 0;
        }
    }

    @Test
    public void testNext() {
        Solution solution = new Solution();
        System.out.println(Arrays.toString(solution.getNextArray("ababababab")));
        System.out.println(Arrays.toString(solution.getNextArray("issip")));
        System.out.println(Arrays.toString(solution.getNextArray("abcababcab")));
        System.out.println(Arrays.toString(solution.getNextArray("abab")));
    }

}
