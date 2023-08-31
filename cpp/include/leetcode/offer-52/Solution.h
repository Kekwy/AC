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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        for (ListNode *p = headA; p != nullptr; p = p->next) lenA++;
        for (ListNode *p = headB; p != nullptr; p = p->next) lenB++;
        ListNode *ptrA = headA, *ptrB = headB;
        if (lenA > lenB) {
            for (int i = 0, skip = lenA - lenB; i < skip; i++, ptrA = ptrA->next);
        } else if (lenA < lenB) {
            for (int i = 0, skip = lenB - lenA; i < skip; i++, ptrB = ptrB->next);
        }
        for (; ptrA != nullptr; ptrA = ptrA->next, ptrB = ptrB->next) {
            if (ptrA == ptrB) return ptrA;
        }
        return nullptr;
    }
};

#endif //CPP_SOLUTION_H
