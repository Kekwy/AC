/*
 * @lc app=leetcode.cn id=547 lang=cpp
 * @lcpr version=21914
 *
 * [547] 省份数量
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

    void travel(int i, vector<vector<int>> &isConnected, vector<int> &isVisited) {
        isVisited[i] = 1;
        for (int j = 0; j < isConnected[i].size(); j++) {
            if (isConnected[i][j] && !isVisited[j]) travel(j, isConnected, isVisited);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int res = 0;
        auto isVisited = vector<int>(isConnected.size(), 0);
        for (int i = 0; i < isVisited.size(); i++) {
            if (!isVisited[i]) {
                res++;
                travel(i, isConnected, isVisited);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */

