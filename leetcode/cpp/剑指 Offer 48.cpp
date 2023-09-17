/*
 * @lc app=leetcode.cn id=剑指 Offer 48 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 48] 最长不含重复字符的子字符串
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
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int lp = 0, rp = 1;
        int res = 1;
        unordered_set<char> hash;
        hash.insert(s[0]);
        while (rp < s.length()) {
            while (hash.find(s[rp]) != hash.end()) {
                hash.erase(s[lp++]);
            }
            hash.insert(s[rp++]);
            res = max(res, rp - lp);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

