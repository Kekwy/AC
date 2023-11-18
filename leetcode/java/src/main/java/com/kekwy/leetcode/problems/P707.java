package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/17 8:45
 */
public class P707 {

    public MyLinkedList myLinkedList = new MyLinkedList();

    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList obj = new MyLinkedList();
     * int param_1 = obj.get(index);
     * obj.addAtHead(val);
     * obj.addAtTail(val);
     * obj.addAtIndex(index,val);
     * obj.deleteAtIndex(index);
     */
    class MyLinkedList {

        private static class ListNode {
            int val;
            ListNode next;

            ListNode() {
                this.val = 0;
                next = null;
            }

            ListNode(int val, ListNode next) {
                this.val = val;
                this.next = next;
            }
        }

        private final ListNode head; // 表头（带头结点）
        private ListNode tail; // 表尾
        private int size;      // 链表中的数据结点数

        public MyLinkedList() {
            this.head = new ListNode();
            this.tail = head;
            this.size = 0;
        }

        private ListNode findAtIndex(int index) {
            // 提取逻辑重复的查找操作，用于解决重复耦合
            if (index >= size || index < -1) { // 防御式编程
                return null;
            }
            ListNode res = head;
            for (int i = 0; i <= index; i++) {
                res = res.next;
            }
            return res;
        }

        public int get(int index) {
            ListNode node = findAtIndex(index);
            if (node == null) return -1;
            return node.val;
        }

        private void addNode(ListNode node, int val) {
            node.next = new ListNode(val, node.next);
            size++;
            if (node == tail) {
                tail = node.next;
            }
        }

        public void addAtHead(int val) {
            addNode(head, val);
        }

        public void addAtTail(int val) {
            addNode(tail, val);
        }

        public void addAtIndex(int index, int val) {
            ListNode node = findAtIndex(index - 1);
            if (node == null) return;
            addNode(node, val);
        }

        private void deleteNode(ListNode node) {
            if (node.next == tail) {
                tail = node;
            }
            node.next = node.next.next;
            size--;
        }

        public void deleteAtIndex(int index) {
            ListNode node = findAtIndex(index - 1);
            if (node == null || node.next == null) return;
            deleteNode(node);
        }
    }

}
