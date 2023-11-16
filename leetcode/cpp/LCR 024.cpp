/*
 * @lc app=leetcode.cn id=LCR 024 lang=cpp
 * @lcpr version=30102
 *
 * [LCR 024] 反转链表
 */


 // @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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

// @lcpr-template-end
// @lc code=start

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *p = head;
        ListNode *q = nullptr;
        while (p != nullptr) {
            ListNode *tmp = p;
            p = p->next;
            tmp->next = q;
            q = tmp;
        }
        return q;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

