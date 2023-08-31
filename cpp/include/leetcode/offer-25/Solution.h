//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        ListNode *dummyHead = new ListNode(-1);
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode *ptr;
        for (ptr = dummyHead; ptr1 != nullptr && ptr2 != nullptr; ptr = ptr->next) {
            if (ptr1->val <= ptr2->val) {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
        }
        if (ptr1 == nullptr) ptr->next = ptr2;
        else ptr->next = ptr1;

        ListNode *res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};

#endif //CPP_SOLUTION_H
