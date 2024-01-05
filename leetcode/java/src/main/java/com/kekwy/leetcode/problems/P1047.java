package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/30 23:52
 */
public class P1047 {
    class Solution {
        public String removeDuplicates(String s) {
            // 用字符串代替栈，避免还要从栈转化为字符串以及字符串反转
            StringBuilder builder = new StringBuilder();
            int top = -1;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (top != -1 && builder.charAt(top) == c) {
                    builder.deleteCharAt(top);
                    top--;
                } else {
                    builder.append(c);
                    top++;
                }
            }
            return builder.toString();
        }
    }
}
