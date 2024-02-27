package com.kekwy.leetcode.problems;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class P28 {
    /**
     * KMP
     */
    class Solution {

        private int[] getNextArray(String pattern) {
            int[] nextArray = new int[pattern.length()];
            int p = 0, q = -1;
            nextArray[p] = q;
            while (p + 1 < pattern.length()) {
//                if (q == -1 || pattern.charAt(p) == pattern.charAt(q)) {
//                    nextArray[++p] = ++q;
//                } else {
//                    q = nextArray[q];
//                }
                // 进行优化，减少重复比较
                while(q >= 0 && pattern.charAt(p) != pattern.charAt(q)) {
                    q = nextArray[q];
                }
                nextArray[++p] = ++q;
            }
            return nextArray;
        }

        public int strStr(String haystack, String needle) {
            int[] nextArray = getNextArray(needle);
            int p = 0, q = 0;
            while (p < haystack.length() && q < needle.length()) {
                if (q == -1 || haystack.charAt(p) == needle.charAt(q)) {
                    p++;
                    q++;
                } else {
                    q = nextArray[q];
                }
            }
            if (q == needle.length()) {
                return p - q;
            } else {
                return -1;
            }
        }
    }

    @Test
    public void testNext() {
        Solution solution = new Solution();
        System.out.println(Arrays.toString(solution.getNextArray("aabaaf")));
        System.out.println(Arrays.toString(solution.getNextArray("issip")));
        System.out.println(solution.strStr("mississippi", "issip"));
    }
}
