package com.kekwy.leetcode.problems;

import java.util.Map;
import java.util.Set;
import java.util.Stack;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/30 23:35
 */
public class P20 {
    class Solution {

        // 消除逻辑内聚和重复耦合
        private Set<Character> leftParenthesesSet = Set.of('{', '[', '(');

        private Map<Character, Character> parenthesesMap = Map.of(
                '}', '{',
                ']', '[',
                ')', '('
        );

        public boolean isValid(String s) {
            Stack<Character> stack = new Stack<>();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (leftParenthesesSet.contains(c)) {
                    stack.push(c);
                } else if (!stack.empty()
                        && stack.peek() == parenthesesMap.get(c)) {
                    stack.pop();
                } else {
                    return false;
                }
            }
            return stack.empty();
        }
    }
}


