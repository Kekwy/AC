//
// Created by Kekwy on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = nullptr;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            if (ptr->val == val) {
                if (pre == nullptr) {
                    head = ptr->next;
                    delete ptr;
                    ptr = head;
                } else {
                    pre->next = ptr->next;
                    delete ptr;
                    ptr = pre->next;
                }
            } else { // 
                pre = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};

#endif //CPP_SOLUTION_H
