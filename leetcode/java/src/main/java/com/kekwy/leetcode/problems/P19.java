package com.kekwy.leetcode.problems;

import com.kekwy.leetcode.util.ListNode;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/18 15:46
 */
public class P19 {
    class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            ListNode dummyNode = new ListNode();
            dummyNode.next = head;
            // 滑动窗口
            ListNode right = dummyNode;
            ListNode left = dummyNode;
            int k = n + 1;
            // 窗口右指针先走 k 步，窗口大小变为 k+1
            for (int i = 0; i < k; i++) {
                right = right.next;
            }
            // 窗口左右指针同时向左移动，保持窗口大小不变
            // 当右指针指向表尾结点的后继（变为空指针）时，
            // 左指针指向的结点即为该链表的倒数第 k 个结点
            while (right != null) {
                right = right.next;
                left = left.next;
            }
            // 倒数第 k (k=n+1) 个结点的后继即为倒数第 n 个结点
            // 删除倒数第 n+1 个结点的后继结点即可
            left.next = left.next.next;
            return dummyNode.next;
        }
    }
}
