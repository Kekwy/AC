package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/20 0:16
 */
public class P344 {
    class Solution {
        public void reverseString(char[] s) {
            int lp = 0, rp = s.length - 1;
            while (lp < rp) {
                char tmp = s[lp];
                s[lp] = s[rp];
                s[rp] = tmp;
                lp++;
                rp--;
            }
        }
    }
}
