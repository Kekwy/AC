//
// Created by Kekwy on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;
        if (p != nullptr) {
            ListNode *q = head->next;
            if (q != nullptr) {
                ListNode *next = swapPairs(q->next);
                p->next = next;
                q->next = p;
                p = q;
            }
        }
        return p;
    }
};

#endif //CPP_SOLUTION_H
