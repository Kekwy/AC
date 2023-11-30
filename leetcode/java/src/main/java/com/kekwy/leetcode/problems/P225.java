package com.kekwy.leetcode.problems;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/29 23:50
 */
public class P225 {
    class MyStack {

        Queue<Integer> queue;

        public MyStack() {
            queue = new ArrayDeque<>();
        }

        public void push(int x) {
            queue.offer(x);
        }

        private void adjust() {
            int size = queue.size();
            for (int i = 0; i < size - 1; i++) {
                queue.offer(queue.poll());
            }
        }

        public int pop() {
            if (empty()) return -1;
            adjust();
            return queue.poll();
        }

        public int top() {
            if (empty()) return -1;
            adjust();
            int res = queue.poll();
            queue.offer(res);
            return res;
        }

        public boolean empty() {
            return queue.isEmpty();
        }
    }
}

class MyStack {

    Queue<Integer> queue;

    public MyStack() {
        queue = new ArrayDeque<>();
    }

    public void push(int x) {
        queue.offer(x);
    }

    private void adjust() {
        int size = queue.size();
        for (int i = 0; i < size - 1; i++) {
            queue.offer(queue.poll());
        }
    }

    public int pop() {
        if (empty()) return -1;
        adjust();
        return queue.poll();
    }

    public int top() {
        if (empty()) return -1;
        adjust();
        int res = queue.poll();
        queue.offer(res);
        return res;
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}