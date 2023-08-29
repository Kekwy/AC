//
// Created by Kekwy on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

class MyLinkedList {

    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val, ListNode *next): val(val), next(next) {}
    };
    
    ListNode *head;

    int length;

public:
    MyLinkedList() {
        head = new ListNode(-1, nullptr);
        length = 0;
    }
    
    int get(int index) {
        if (index >= length) return -1;
        ListNode *ptr = head;
        for (int i = 0; i <= index; i++) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(length, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index >= 0 && index <= length) {
            ListNode *ptr = head;
            for (int i = 0; i < index; i++) {
                ptr = ptr->next;
            }
            ptr->next = new ListNode(val, ptr->next);
            length++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= 0 && index < length) {
            ListNode *ptr = head;
            for (int i = 0; i < index; i++) {
                ptr = ptr->next;
            }
            ListNode *next = ptr->next;
            ptr->next = next->next;
            delete next;
            length--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#endif //CPP_SOLUTION_H
