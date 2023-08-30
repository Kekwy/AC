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
        Edge *graph[ARR_SIZE] = {nullptr};
        bool isForbidden[ARR_SIZE] = {false};
        bool visited[ARR_SIZE] = {false};
        for (int i = 0; i < forbidden.size(); i++) {
            isForbidden[forbidden[i]] = true;
        }

        // 利用广度优先建图
        auto buildBFS = queue<int>();
        buildBFS.push(0);
        while (!buildBFS.empty()) {
            int i = buildBFS.front();
            buildBFS.pop();
            int r = i + a;
            int l = i - b;
            if (r < ARR_SIZE && r - b * 2 <= x && !isForbidden[r]) {
                graph[i] = new Edge(r, false, graph[i]);
                if (r != x && !visited[r]) {
                    buildBFS.push(r);
                }
            }
            if (l >= 0 && !isForbidden[l]) {                // else if
                graph[i] = new Edge(l, true, graph[i]);     // new Edge(r, true, graph[i]);
                if (l != x && !visited[l]) {
                    buildBFS.push(l);
                }
            }
            visited[i] = true; // 避免死循环
        }
        
        // 利用动态规划进行优化，dp[i][j] 表示由回退 j 次到达 i 结点时，i 结点到 x 结点的最短路径
        int dp[ARR_SIZE][3] = {{0, 0, 0}};

        runDP(0, x, 0, graph, dp);

        int res = dp[0][0];

        // 归还内存
        for (int i = 0; i < ARR_SIZE; i++) {
            Edge *p = graph[i];
            Edge *q = nullptr;
            while (p != nullptr) {
                q = p;
                p = p->next;
                delete q;
            }
        }

        return res;
    }
};

#endif //CPP_SOLUTION_H
