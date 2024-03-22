package com.kekwy.leetcode.util;

/**
 * Definition for singly-linked list.
 */
public class ListNode {
    public int val;
    public ListNode next;

    public ListNode() {
    }

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    public static ListNode toList(int[] array) {
        ListNode dummyHead = new ListNode();
        ListNode p = dummyHead;
        for (int i : array) {
            p.next = new ListNode(i);
            p = p.next;
        }
        return dummyHead.next;
    }

}
