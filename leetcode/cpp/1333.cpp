/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 * @lcpr version=21917
 *
 * [1333] 餐厅过滤器
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
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> restaurantsFilter;
        for (vector<int> restaurant : restaurants) {
            if ((!veganFriendly || restaurant[2])
            && restaurant[3] <= maxPrice
            && restaurant[4] <= maxDistance) {
                restaurantsFilter.push_back(restaurant);
            }
        }
        sort(restaurantsFilter.begin(), restaurantsFilter.end(), [](vector<int> a, vector<int> b){
            if (a[1] > b[1] || (a[1] == b[1] && a[0] > b[0])) return 1;
            return 0;
        });
        vector<int> res;
        for (vector<int> restaurant : restaurantsFilter) {
            res.push_back(restaurant[0]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n1\n50\n10\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n50\n10\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n30\n3\n
// @lcpr case=end

 */

