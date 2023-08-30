//
// Created by Kekwy on 2023/8/30.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <queue>

using namespace std;

#define ARR_SIZE 4000

/**
 * tips: Think of the line as a graph.
 */
class Solution {

public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if (x == 0) return 0;
        bool isForbidden[ARR_SIZE] = {false};
        for (int i = 0; i < forbidden.size(); i++) {
            isForbidden[forbidden[i]] = true;
        }

        // 利用广度优先搜索找到到达 x 的最短路径
        auto searchBFS = queue<vector<int>>();
        searchBFS.push({0, 0, 0}); // {结点编号，由回退几次到达，广搜的第几层到达}
        
        // 利用动态规划进行优化，dp[i][j] 表示由连续回退 j 次到达 i 结点时，i 结点到 x 结点的最短路径
        bool visited[ARR_SIZE][3] = {{false, false, false}};

        int res = -1;
        while (!searchBFS.empty()) {
            int i = searchBFS.front()[0];
            int back = searchBFS.front()[1];
            int length = searchBFS.front()[2];
            searchBFS.pop();

            visited[i][back] = true; // 避免死循环

            if (i == x) { // 由于使用广搜，后续找到的路径只可能比当前值大
                res = length;
                break;
            } else {
                int r = i + a;
                int l = i - b;
                if (r < ARR_SIZE && !isForbidden[r] && (r <= x || a < b * 2)) {
                    if (!visited[r][0]) {
                        searchBFS.push({r, 0, length + 1});
                    }
                }
                if (l >= 0 && !isForbidden[l]) {
                    if (back < 2 && !visited[l][back + 1]) {
                        searchBFS.push({l, back + 1, length + 1});
                    }
                }
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H
