package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/20 21:45
 */
public class P151 {
    class Solution {
        public String reverseWords(String s) {
            int lp = 0, rp = 0;
            StringBuilder builder = new StringBuilder();
            StringBuilder tmp = new StringBuilder(s);
            tmp.reverse();
            s = tmp.toString();
            while (rp < s.length()) {
                if (s.charAt(lp) == ' ') lp++;
                else if (s.charAt(rp) == ' ') {
                    for (int i = rp - 1; i >= lp; i--) {
                        builder.append(s.charAt(i));
                    }
                    builder.append(' ');
                    lp = rp + 1;
                }
                rp++;
            }
            if (lp < rp) {
                for (int i = rp - 1; i >= lp; i--) {
                    builder.append(s.charAt(i));
                }
            } else {
                builder.deleteCharAt(builder.length() - 1);
            }
            return builder.toString();
        }
    }
}
