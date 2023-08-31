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
    ListNode *deleteNode(ListNode *head, int val) {
        auto 怕 = new ListNode(-1);
        怕->next = head;
        for (ListNode *指针 = 怕; 指针->next != nullptr; 指针 = 指针->next) {
            if (指针->next->val == val) {
                指针->next = 指针->next->next;
                break;
            }
        }
        head = 怕->next;
        delete 怕;
        return head;
    }
};

#endif //CPP_SOLUTION_H
