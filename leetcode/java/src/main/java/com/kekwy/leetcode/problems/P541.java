package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/20 0:28
 */
public class P541 {

    class Solution {

        private void reverse(char[] s, int begin, int end) {
            int lp = begin, rp = end - 1;
            while (lp < rp) {
                char tmp = s[lp];
                s[lp] = s[rp];
                s[rp] = tmp;
                lp++;
                rp--;
            }
        }

        public String reverseStr(String s, int k) {
            char[] ch = s.toCharArray();
            int step = k * 2;
            for (int i = 0; i < ch.length; i += step) {
                reverse(ch, i, Math.min(i + k, ch.length));
            }
            return new String(ch);
        }
    }

}
