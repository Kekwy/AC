// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2603 lang=cpp
 * @lcpr version=21914
 *
 * [2603] 收集树中金币
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
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        auto degrees = vector<int>(coins.size(), 0);
        auto graph = vector<vector<int>>(coins.size());
        // 计算各节点的度数
        for (vector<int> edge : edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        // 删去所有没有金币的叶子结点
        for (int i = 0; i < degrees.size();i++) {
            if (degrees[i] == 1 && coins[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            degrees[node]--;
            for (int l : graph[node]) {
                if (degrees[l] == 0) continue;
                degrees[l]--;
                if (degrees[l] == 1 && coins[l] == 0) q.push(l);
            }
        }
        // 删除最外两层的结点
        queue<pair<int, int>> q1;
        for (int i = 0; i < degrees.size();i++) {
            if (degrees[i] == 1) q1.push(make_pair(i, 1));
        }
        while (!q1.empty()) {
            int node = q1.front().first;
            int layer = q1.front().second;
            q1.pop();
            degrees[node]--;
            if (layer == 1) {
                for (int l : graph[node]) {
                    if (degrees[l] == 0) continue;
                    degrees[l]--;
                    if (degrees[l] == 1) q1.push(make_pair(l, 2));
                }
            }
        }
        // 计算当前结点数
        int count = 0;
        for (int d : degrees) {
            if (d > 0) count++;
        }
        if (count > 0) return 2 * (count - 1);
        return 0;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=collectTheCoins
// paramTypes= ["number[]","number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,0,0,0,0,1]\n[[0,1],[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,1,1,0,0,1]\n[[0,1],[0,2],[1,3],[1,4],[2,5],[5,6],[5,7]]\n
// @lcpr case=end

 */

