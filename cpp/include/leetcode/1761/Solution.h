//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <queue>

using namespace std;

class Solution {

    void quickSort(vector<int> nodes, vector<int> degrees, int begin, int end) {
        if (begin >= end) return;
        int pivot = nodes[begin];
        int lPtr = begin, rPtr = end - 1;
        bool flag = false;
        while (lPtr < rPtr) {
            if (flag) {
                if (degrees[nodes[lPtr]] > degrees[pivot]) {
                    nodes[rPtr] = nodes[lPtr];
                    rPtr--;
                    flag = false;
                } else {
                    lPtr++;
                }
            } else {
                if (degrees[nodes[rPtr]] < degrees[pivot]) {
                    nodes[lPtr] = nodes[rPtr];
                    lPtr++;
                    flag = true;
                } else {
                    rPtr--;
                }
            }
        }
        nodes[lPtr] = pivot;
        quickSort(nodes, degrees, begin, lPtr);
        quickSort(nodes, degrees, lPtr + 1, end);
    }

public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        auto graph = vector<vector<int>>(n, vector<int>(n, 0));
        auto degrees = vector<int>(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            degrees[u]++;
            degrees[v]++;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        // auto nodes = vector<int>(n);
        // for (int i = 0; i < n; i++) {
        //     nodes[i] = i;
        // }
        // quickSort(nodes, degrees, 0, n); // 此处排序操作无法对算法进行优化
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] == 1) {
                    for (int t = j + 1; t < n; t++) {
                        if (graph[i][t] && graph[t][j] == 1) {
                            int sum = degrees[i] + degrees[j] + degrees[t] - 6;
                            if (res == -1 || res > sum) {
                                res = sum;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H
