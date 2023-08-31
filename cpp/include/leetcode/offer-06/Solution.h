//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <stack>

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
    vector<int> reversePrint(ListNode *head) {
        auto s = stack<int>();
        for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
            s.push(ptr->val);
        }
        auto res = vector<int>();
        for (; !s.empty(); s.pop()) {
            res.push_back(s.top());
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H
