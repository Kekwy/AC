/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 * @lcpr version=21917
 *
 * [1488] 避免洪水泛滥
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
    vector<int> avoidFlood(vector<int> &rains) {
        vector<pair<int, int>> pools;
        unordered_set<int> set;
        int ptr = 0;
        for (int i = 0; i < rains.size(); i++) {
            int rain = rains[i];
            if (rain > 0) {
                if (set.find(rain) != set.end()) {
                    if (ptr == pools.size()) {
                        return vector<int>();
                    } else {
                        pools[ptr++].second = rain;
                    }
                } else {
                    set.insert(rain);
                }
            } else {
                pools.push_back(make_pair(i, 2));
            }
        }
        vector<int> res = vector<int>(rains.size(), -1);
        for (pair<int, int> pool : pools) {
            res[pool.first] = pool.second;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,0,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,1,2]\n
// @lcpr case=end

 */

