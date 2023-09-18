/*
 * @lc app=leetcode.cn id=剑指 Offer 45 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 45] 把数组排成最小的数
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
    string minNumber(vector<int> &nums) {
        vector<string> strNums;
        for (const int &n : nums) {
            strNums.push_back(to_string(n));
        }
        sort(strNums.begin(), strNums.end(), [](const string &s1, const string &s2) {
            return s1 + s2 < s2 + s1;
        });
        string res;
        for (const string &s : strNums) {
            res += s;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,30,34,5,9]\n
// @lcpr case=end

 */

