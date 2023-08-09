//
// Created by Kekwy on 2023/8/9.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

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

    ListNode *helper(ListNode *cur, ListNode *pre) {
        ListNode *next = cur->next;
        cur->next = pre;
        if (next == nullptr) return cur;
        return helper(next, cur);
    }

public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return head;
        return helper(head, nullptr);
    }
};

#endif //CPP_SOLUTION_H
