package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.ListNode;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/18 13:13
 */
public class P206 {

    class Solution {
        public ListNode reverseList(ListNode head) {
            ListNode curr = head;
            ListNode prev = null;
            while (curr != null) {
                ListNode tmp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = tmp;
            }
            return prev;
        }

        // 递归版
        private ListNode recur(ListNode curr, ListNode prev) {
            if (curr == null) return prev;
            ListNode tmp = curr.next;
            curr.next = prev;
            return recur(tmp, curr);
        }

    }

}
