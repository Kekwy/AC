/*
 * @lc app=leetcode.cn id=841 lang=cpp
 * @lcpr version=21914
 *
 * [841] 钥匙和房间
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

    vector<int> isVisited;

    void travel(int node, vector<vector<int>> &rooms) {
        isVisited[node] = 1;
        for (int l : rooms[node]) {
            if (!isVisited[l]) travel(l, rooms);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        isVisited.resize(rooms.size(), 0);
        travel(0, rooms);
        for (int i : isVisited) {
            if (!i) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[3,0,1],[2],[0]]\n
// @lcpr case=end

 */

