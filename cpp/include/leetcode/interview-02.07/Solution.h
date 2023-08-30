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

// 时间复杂度 O(n) 、仅用 O(1) 内存的解决方案
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;
        int lenA = 0;
        int lenB = 0;
        for (; p != nullptr; lenA++, p = p->next);
        for (; q != nullptr; lenB++, q = q->next);
        p = headA;
        q = headB;
        if (lenA > lenB) {
            int skip = lenA - lenB;
            for(int i = 0; i < skip; i++, p = p->next); 
        } else {
            int skip = lenB - lenA;
            for(int i = 0; i < skip; i++, q = q->next); 
        }
        while(p != nullptr) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};

#endif //CPP_SOLUTION_H
