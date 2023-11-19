package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.ListNode;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/18 20:00
 */
public class P142 {
    class Solution {
        public ListNode detectCycle(ListNode head) {
            // 快慢指针
            ListNode slow = head, quick = head;
            while (quick != null && quick.next != null) {
                slow = slow.next;
                quick = quick.next.next;
                if (quick == slow) break;
            }
            if (quick == null || quick.next == null) {
                return null;
            }
            quick = head;
            while (quick != slow) {
                quick = quick.next;
                slow = slow.next;
            }
            return quick;
        }
    }
}
