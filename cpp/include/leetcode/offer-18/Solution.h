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
    ListNode *getKthFromEnd(ListNode *head, int k) {
        if (head == nullptr) return head;
        ListNode *p = head, *q = head;
        int winSize = 0;
        for (; p != nullptr; p = p->next) {
            if (winSize < k) {
                winSize++;
            } else {
                q = q->next;
            }
        }
        if (winSize < k) return nullptr;
        else return q;
    }
};

#endif //CPP_SOLUTION_H
