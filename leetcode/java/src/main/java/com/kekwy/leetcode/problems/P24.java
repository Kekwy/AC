package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.ListNode;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/18 15:27
 */
public class P24 {

    class Solution {
        public ListNode swapPairs(ListNode head) {
            ListNode dummyHead = new ListNode();
            dummyHead.next = head;
            ListNode curr = head;
            ListNode prev = dummyHead;
            while (curr != null && curr.next != null) {
                ListNode tmp = curr.next;
                curr.next = tmp.next;
                tmp.next = curr;
                prev.next = tmp;
                prev = curr;
                curr = curr.next;
            }
            return dummyHead.next;
        }
    }

}
