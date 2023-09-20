/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=21914
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> wordGroups;
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if (wordGroups.find(tmp) != wordGroups.end()) {
                wordGroups[tmp].push_back(s);
            } else {
                wordGroups[tmp] = { s };
            }
        }
        for (pair<string, vector<string>> group : wordGroups) {
            res.push_back(group.second);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

