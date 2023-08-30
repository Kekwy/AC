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

    struct Edge {
        int to;
        bool isBack;
        Edge *next;
        Edge(int to, bool isBack, Edge *next): to(to), isBack(isBack), next(next) {}
    };

    void runDP(int i, int dst, int back, Edge *graph[], int dp[][3]) {
        Edge *p = graph[i];
        dp[i][back] = -1;
        while (p != nullptr) {
            int tmpBack = 0;
            if (p->isBack) {
                tmpBack = back + 1;
            }
            if (tmpBack < 2) {
                if (dp[p->to][tmpBack] == -1) {
                    continue;
                } else {
                    if (p->to == dst) {
                        dp[i][back] = 1;
                        return;
                    } else {
                        if (dp[p->to][tmpBack] == 0) {
                            runDP(p->to, dst, tmpBack, graph, dp);
                        }
                        if (dp[i][back] == -1 || dp[i][back] > dp[p->to][tmpBack] + 1) {
                            dp[i][back] = dp[p->to][tmpBack] + 1;
                        }
                    }
                }
            }
            p = p->next;
        }
    }

public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if (x == 0) return 0;
        bool isForbidden[ARR_SIZE] = {false};
        for (int i = 0; i < forbidden.size(); i++) {
            isForbidden[forbidden[i]] = true;
        }

        // 利用广度优先搜索找到到达 x 的最短路径
        auto searchBFS = queue<int[3]>();
        searchBFS.push({0, 0, 0}); // {结点编号，由回退几次到达，广搜的第几层到达}
        
        // 利用动态规划进行优化，dp[i][j] 表示由连续回退 j 次到达 i 结点时，i 结点到 x 结点的最短路径
        bool visited[ARR_SIZE][3] = {{false, false, false}};

        int res = -1;
        while (!searchBFS.empty()) {
            int i = searchBFS.front()[0];
            int back = searchBFS.front()[1];
            int length = searchBFS.front()[2];
        }

        return res;
    }
};

#endif //CPP_SOLUTION_H
