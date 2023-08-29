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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *p = head;
        ListNode *q = dummyHead;
        int winSize = 1;
        while (p != nullptr) {
            if (winSize > n) {
                q = q->next;
            } else {
                winSize++;
            }
            p = p->next;
        }
        ListNode *tmp = q->next;
        q->next = tmp->next;
        delete tmp;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

#endif //CPP_SOLUTION_H
