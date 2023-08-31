//
// Created by Kekwy on 2023/8/30.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *quick = head;

        while (quick != nullptr && quick->next != nullptr) { // quick 指针判空
            slow = slow->next;
            quick = quick->next->next;
            if (slow == quick) {
                break;
            }
        }

        if (quick == nullptr || quick->next == nullptr) return nullptr; // quick 指针判空

        ListNode *p = head, *q = slow;
        for (; p != q; p = p->next, q = q->next);

        return p;
    }
};

#endif //CPP_SOLUTION_H
