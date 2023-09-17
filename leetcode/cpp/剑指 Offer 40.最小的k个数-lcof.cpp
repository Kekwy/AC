/*
 * @lc app=leetcode.cn id=剑指 Offer 40 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 40] 最小的k个数
 */
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
// @lc code=start
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> que;
        for (int a : arr) {
            que.push(a);
            if (!que.empty() && que.size() > k) {
                que.pop();
            }
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,1]\n1\n
// @lcpr case=end

 */

