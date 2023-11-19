package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.ListNode;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/18 19:48
 */
public class LCCI0207 {
    class Solution {
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            int lenA = 0, lenB = 0;
            for (ListNode p = headA; p != null; p = p.next) lenA++;
            for (ListNode p = headB; p != null; p = p.next) lenB++;
            ListNode nodeA = headA, nodeB = headB;
            int lenDiff = Math.abs(lenA - lenB);
            if (lenA > lenB) {
                for (int i = 0; i < lenDiff; i++) nodeA = nodeA.next;
            } else {
                for (int i = 0; i < lenDiff; i++) nodeB = nodeB.next;
            }
            ListNode res = null;
            while (nodeA != null && nodeB != null) {
                if (nodeA == nodeB) {
                    res = nodeA;
                    break;
                }
                nodeA = nodeA.next;
                nodeB = nodeB.next;
            }
            return res;
        }
    }
}
