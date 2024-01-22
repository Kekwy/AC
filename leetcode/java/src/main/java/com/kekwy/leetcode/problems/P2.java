package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.ListNode;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/22 19:45
 */
public class P2 {

    class Solution {

        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode dummyHead = new ListNode();
            ListNode ptr = dummyHead;
            ListNode p1 = l1, p2 = l2;
            int inc = 0;
            for (; p1 != null && p2 != null; p1 = p1.next, p2 = p2.next, ptr = ptr.next) {
                int sum = p1.val + p2.val + inc;
                inc = sum / 10;
                ptr.next = new ListNode(sum % 10);
            }
            for (; p1 != null; p1 = p1.next, ptr = ptr.next) {
                int sum = p1.val + inc;
                inc = sum / 10;
                ptr.next = new ListNode(sum % 10);
            }
            for (; p2 != null; p2 = p2.next, ptr = ptr.next) {
                int sum = p2.val + inc;
                inc = sum / 10;
                ptr.next = new ListNode(sum % 10);
            }
            if (inc != 0) {
                ptr.next = new ListNode(inc);
            }
            return dummyHead.next;
        }

    }

}
