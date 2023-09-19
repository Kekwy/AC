/*
 * @lc app=leetcode.cn id=802 lang=cpp
 * @lcpr version=21914
 *
 * [802] 找到最终的安全状态
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

    // 0 未访问，1 是当前正在访问节点的父结点，2 完成访问且有环，3 完成访问且无环
    vector<int> isVisited;

    vector<int> res;

    void travel(int n, vector<vector<int>> &graph) {
        isVisited[n] = 1;
        for (int i = 0; i < graph[n].size(); i++) {
            int l = graph[n][i];
            if (!isVisited[l]) travel(l, graph);
            if (isVisited[l] == 1 || isVisited[l] == 2) {
                isVisited[n] = 2;
                return;
            }
        }
        isVisited[n] = 3;
        res.push_back(n);
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        isVisited.resize(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (!isVisited[i]) travel(i, graph);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[5],[0],[5],[],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[1,2],[3,4],[0,4],[]]\n
// @lcpr case=end

 */

