package com.kekwy.leetcode.problems;

import java.util.Stack;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/29 23:31
 */
public class P232 {
    class MyQueue {

        Stack<Integer> inStack;

        Stack<Integer> outStack;

        public MyQueue() {
            inStack = new Stack<>();
            outStack = new Stack<>();
        }

        public void push(int x) {
            inStack.push(x);
        }

        private void adjust() {
            while (!inStack.empty()) {
                outStack.push(inStack.pop());
            }
        }

        private boolean check() {
            if (inStack.empty() && outStack.empty()) {
                return false;
            }
            if (outStack.empty()) {
                adjust();
            }
            return true;
        }

        public int pop() {
            if (!check()) return -1;
            return outStack.pop();
        }

        public int peek() {
            if (!check()) return -1;
            return outStack.peek();
        }

        public boolean empty() {
            return inStack.empty() && outStack.empty();
        }
    }
}
