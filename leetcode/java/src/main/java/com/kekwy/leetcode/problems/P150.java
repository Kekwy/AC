package com.kekwy.leetcode.problems;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.function.BiConsumer;
import java.util.function.BinaryOperator;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/12/1 0:11
 */
public class P150 {
    class Solution {

        // 符合 OCP
        private Map<String, BinaryOperator<Integer>> optMap = Map.of(
                "+", (a, b) -> a + b,
                "-", (a, b) -> a - b,
                "*", (a, b) -> a * b,
                "/", (a, b) -> a / b
        );

        public int evalRPN(String[] tokens) {
            Stack<Integer> stack = new Stack<>();
            for (String token : tokens) {
                if (optMap.containsKey(token)) {
                    int a = stack.pop();
                    int b = stack.pop();
                    stack.push(optMap.get(token).apply(a, b));
                } else {
                    stack.push(Integer.valueOf(token));
                }
            }
            return stack.pop();
        }
    }
}
