package com.kekwy.leetcode.problems;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/12/1 0:28
 */
public class P239 {

    class MyQueue {

        private final Deque<Integer> deque = new ArrayDeque<>();

        public void offer(int i) {
            while (!deque.isEmpty() && deque.peekLast() < i) deque.pollLast();
            deque.offerLast(i);
        }

        public void remove(int i) {
            if (!deque.isEmpty() && deque.peekFirst() == i) {
                deque.pollFirst();
            }
        }

        public int peek() {
            if (!deque.isEmpty()) {
                return deque.peekFirst();
            }
            return -1;
        }

    }

    class Solution {

        public int[] maxSlidingWindow(int[] nums, int k) {
            MyQueue queue = new MyQueue();
            int[] res = new int[nums.length - k + 1];
            int num = 0;
            for (int i = 0; i < k; i++) {
                queue.offer(nums[i]);
            }
            res[num++] = queue.peek();
            for (int i = k; i < nums.length; i++) {
                queue.offer(nums[i]);
                queue.remove(nums[i - k]);
                res[num++] = queue.peek();
            }
            return res;
        }
    }

}
