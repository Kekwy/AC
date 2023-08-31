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
